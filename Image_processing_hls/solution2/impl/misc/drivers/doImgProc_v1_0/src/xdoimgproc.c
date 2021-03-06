// ==============================================================
// File generated on Thu Apr 11 00:03:33 EDT 2019
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
/***************************** Include Files *********************************/
#include "xdoimgproc.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XDoimgproc_CfgInitialize(XDoimgproc *InstancePtr, XDoimgproc_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Crtl_bus_BaseAddress = ConfigPtr->Crtl_bus_BaseAddress;
    InstancePtr->Kernel_bus_BaseAddress = ConfigPtr->Kernel_bus_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XDoimgproc_Start(XDoimgproc *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XDoimgproc_ReadReg(InstancePtr->Crtl_bus_BaseAddress, XDOIMGPROC_CRTL_BUS_ADDR_AP_CTRL) & 0x80;
    XDoimgproc_WriteReg(InstancePtr->Crtl_bus_BaseAddress, XDOIMGPROC_CRTL_BUS_ADDR_AP_CTRL, Data | 0x01);
}

u32 XDoimgproc_IsDone(XDoimgproc *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XDoimgproc_ReadReg(InstancePtr->Crtl_bus_BaseAddress, XDOIMGPROC_CRTL_BUS_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XDoimgproc_IsIdle(XDoimgproc *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XDoimgproc_ReadReg(InstancePtr->Crtl_bus_BaseAddress, XDOIMGPROC_CRTL_BUS_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XDoimgproc_IsReady(XDoimgproc *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XDoimgproc_ReadReg(InstancePtr->Crtl_bus_BaseAddress, XDOIMGPROC_CRTL_BUS_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XDoimgproc_EnableAutoRestart(XDoimgproc *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XDoimgproc_WriteReg(InstancePtr->Crtl_bus_BaseAddress, XDOIMGPROC_CRTL_BUS_ADDR_AP_CTRL, 0x80);
}

void XDoimgproc_DisableAutoRestart(XDoimgproc *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XDoimgproc_WriteReg(InstancePtr->Crtl_bus_BaseAddress, XDOIMGPROC_CRTL_BUS_ADDR_AP_CTRL, 0);
}

void XDoimgproc_Set_operation(XDoimgproc *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XDoimgproc_WriteReg(InstancePtr->Crtl_bus_BaseAddress, XDOIMGPROC_CRTL_BUS_ADDR_OPERATION_DATA, Data);
}

u32 XDoimgproc_Get_operation(XDoimgproc *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XDoimgproc_ReadReg(InstancePtr->Crtl_bus_BaseAddress, XDOIMGPROC_CRTL_BUS_ADDR_OPERATION_DATA);
    return Data;
}

u32 XDoimgproc_Get_kernel_BaseAddress(XDoimgproc *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Kernel_bus_BaseAddress + XDOIMGPROC_KERNEL_BUS_ADDR_KERNEL_BASE);
}

u32 XDoimgproc_Get_kernel_HighAddress(XDoimgproc *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Kernel_bus_BaseAddress + XDOIMGPROC_KERNEL_BUS_ADDR_KERNEL_HIGH);
}

u32 XDoimgproc_Get_kernel_TotalBytes(XDoimgproc *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XDOIMGPROC_KERNEL_BUS_ADDR_KERNEL_HIGH - XDOIMGPROC_KERNEL_BUS_ADDR_KERNEL_BASE + 1);
}

u32 XDoimgproc_Get_kernel_BitWidth(XDoimgproc *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XDOIMGPROC_KERNEL_BUS_WIDTH_KERNEL;
}

u32 XDoimgproc_Get_kernel_Depth(XDoimgproc *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XDOIMGPROC_KERNEL_BUS_DEPTH_KERNEL;
}

u32 XDoimgproc_Write_kernel_Words(XDoimgproc *InstancePtr, int offset, int *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XDOIMGPROC_KERNEL_BUS_ADDR_KERNEL_HIGH - XDOIMGPROC_KERNEL_BUS_ADDR_KERNEL_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Kernel_bus_BaseAddress + XDOIMGPROC_KERNEL_BUS_ADDR_KERNEL_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XDoimgproc_Read_kernel_Words(XDoimgproc *InstancePtr, int offset, int *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XDOIMGPROC_KERNEL_BUS_ADDR_KERNEL_HIGH - XDOIMGPROC_KERNEL_BUS_ADDR_KERNEL_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Kernel_bus_BaseAddress + XDOIMGPROC_KERNEL_BUS_ADDR_KERNEL_BASE + (offset + i)*4);
    }
    return length;
}

u32 XDoimgproc_Write_kernel_Bytes(XDoimgproc *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XDOIMGPROC_KERNEL_BUS_ADDR_KERNEL_HIGH - XDOIMGPROC_KERNEL_BUS_ADDR_KERNEL_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Kernel_bus_BaseAddress + XDOIMGPROC_KERNEL_BUS_ADDR_KERNEL_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XDoimgproc_Read_kernel_Bytes(XDoimgproc *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XDOIMGPROC_KERNEL_BUS_ADDR_KERNEL_HIGH - XDOIMGPROC_KERNEL_BUS_ADDR_KERNEL_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Kernel_bus_BaseAddress + XDOIMGPROC_KERNEL_BUS_ADDR_KERNEL_BASE + offset + i);
    }
    return length;
}

void XDoimgproc_InterruptGlobalEnable(XDoimgproc *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XDoimgproc_WriteReg(InstancePtr->Crtl_bus_BaseAddress, XDOIMGPROC_CRTL_BUS_ADDR_GIE, 1);
}

void XDoimgproc_InterruptGlobalDisable(XDoimgproc *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XDoimgproc_WriteReg(InstancePtr->Crtl_bus_BaseAddress, XDOIMGPROC_CRTL_BUS_ADDR_GIE, 0);
}

void XDoimgproc_InterruptEnable(XDoimgproc *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XDoimgproc_ReadReg(InstancePtr->Crtl_bus_BaseAddress, XDOIMGPROC_CRTL_BUS_ADDR_IER);
    XDoimgproc_WriteReg(InstancePtr->Crtl_bus_BaseAddress, XDOIMGPROC_CRTL_BUS_ADDR_IER, Register | Mask);
}

void XDoimgproc_InterruptDisable(XDoimgproc *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XDoimgproc_ReadReg(InstancePtr->Crtl_bus_BaseAddress, XDOIMGPROC_CRTL_BUS_ADDR_IER);
    XDoimgproc_WriteReg(InstancePtr->Crtl_bus_BaseAddress, XDOIMGPROC_CRTL_BUS_ADDR_IER, Register & (~Mask));
}

void XDoimgproc_InterruptClear(XDoimgproc *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XDoimgproc_WriteReg(InstancePtr->Crtl_bus_BaseAddress, XDOIMGPROC_CRTL_BUS_ADDR_ISR, Mask);
}

u32 XDoimgproc_InterruptGetEnabled(XDoimgproc *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XDoimgproc_ReadReg(InstancePtr->Crtl_bus_BaseAddress, XDOIMGPROC_CRTL_BUS_ADDR_IER);
}

u32 XDoimgproc_InterruptGetStatus(XDoimgproc *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XDoimgproc_ReadReg(InstancePtr->Crtl_bus_BaseAddress, XDOIMGPROC_CRTL_BUS_ADDR_ISR);
}

