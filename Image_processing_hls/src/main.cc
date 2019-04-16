#include <stdio.h>
#include "xaxidma.h"
#include "xdoimgproc.h"
#include "AxiTimerHelper.h"

#define SIZE_ARR (320*240)

#define KERNEL_DIM 3

#define MEM_BASE_ADDR 0x01000000
#define TX_BUFFER_BASE (MEM_BASE_ADDR + 0x00100000)
#define RX_BUFFER_BASE (MEM_BASE_ADDR + 0x00300000)

unsigned char *m_dma_buffer_TX = (unsigned char*)TX_BUFFER_BASE;
unsigned char *m_dma_buffer_RX = (unsigned char*)RX_BUFFER_BASE;

unsigned char imgIn_HW[SIZE_ARR];

int initDMA()
{
	XAxiDma_Config *CfgPtr;
	CfgPtr = XAxiDma_LookupConfig(XPAR_AXI_DMA_0_DEVICE_ID);
	XAxiDma_CfgInitialize(&axiDma, CfgPtr);

	XAxiDma_IntrDisable(&axiDma, XAXIDMA_IRQ_ALL_MASK, XAXIDMA_DEVICE_TO_DMA);
	XAxiDma_IntrDisable(&axiDma, XAXIDMA_IRQ_ALL_MASK, XAXIDMA_DMA_TO_DEVICE);

	return XST_SUCCESS;
}

XDoimgproc doImgProc;
int initDoImgProc()
{
	int status;

	XDoimgproc_Config *doImgProc_cfg;
	doImgProc_cfg = XDoimgproc_LookupConfig(XPAR_DOIMGPROC_0_DEVICE_ID);
	if(!doImgProc_cfg){
		printf("Error loading config\n");
	}
	status = Xdoimgproc_CfgInitialize(&doImgProc, doImgProc_cfg);
	if(status != XST_SUCCESS){
		printf("Error doiung initialization\n");
	}

	return status;

}

char kernel[KERNEL_DIM * KERNEL_DIM] = {
			-1, -1, -1,
			-1,  8, -1,
			-1,  -1, -1,
};

int main()
{
	initDMA();
	initDoImgProc();

	printf("Doing convolution on hardware\n");

	for(int idx = 0 ; idx < SIZE_ARR ; idx++){
		imgIn_HW[idx] = img[idx];
	}

	AxiTimerHelper axiTimer;

	printf("Starting hardware\n");

	XDoimgproc_write_kernel_bytes(&doImgProc, 0, kernel, 9);
	XDoimgproc_Set_operation(&doImgProc, 1);
	XDoimgproc_Start(&doImgProc);

	axiTimer.startTimer();
	xil_DcacheFlushRange((u32)imgIn_HW, SIZE_ARR * sizeof(unsigned char));
	xil_DcacheFlushRange((u32)m_dma_buffer_RX, SIZE_ARR * sizeof(unsigned char));

	XAxiDma_SimpleTransfer(&axiDma, (u32)imgIn_HW, SIZE_ARR*sizeof(unsigned char), XAXIDMA_DMA_TO_DEVICE);
	XAxiDma_SimpleTransfer(&axiDma, (u32)imgIn_HW, SIZE_ARR*sizeof(unsigned char), XAXIDMA_DMA_TO_DEVICE);

	while(XAxiDma_Busy(&axiDma, XAXIDMA_DMA_TO_DEVICE));
	while(XAxiDma_Busy(&axiDma, XAXIDMA_DEVICE_TO_DMA));

	xil_DcacheFlushRange((u32)m_dma_buffer_RX, SIZE_ARR*sizeof(unsigned char));
	axiTimer.stopTimer();

	double hw_elapsed = axiTimer.getElapsedTimerInSeconds();
	printf("HW execution in seconds: %f\n", hw_elapsed);

	return 0;
}

