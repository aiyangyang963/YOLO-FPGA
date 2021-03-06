// ==============================================================
// File generated on Thu Apr 11 00:03:33 EDT 2019
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef XDOIMGPROC_H
#define XDOIMGPROC_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#ifndef __linux__
#include "xil_types.h"
#include "xil_assert.h"
#include "xstatus.h"
#include "xil_io.h"
#else
#include <stdint.h>
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>
#endif
#include "xdoimgproc_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
#else
typedef struct {
    u16 DeviceId;
    u32 Crtl_bus_BaseAddress;
    u32 Kernel_bus_BaseAddress;
} XDoimgproc_Config;
#endif

typedef struct {
    u32 Crtl_bus_BaseAddress;
    u32 Kernel_bus_BaseAddress;
    u32 IsReady;
} XDoimgproc;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XDoimgproc_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XDoimgproc_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XDoimgproc_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XDoimgproc_ReadReg(BaseAddress, RegOffset) \
    *(volatile u32*)((BaseAddress) + (RegOffset))

#define Xil_AssertVoid(expr)    assert(expr)
#define Xil_AssertNonvoid(expr) assert(expr)

#define XST_SUCCESS             0
#define XST_DEVICE_NOT_FOUND    2
#define XST_OPEN_DEVICE_FAILED  3
#define XIL_COMPONENT_IS_READY  1
#endif

/************************** Function Prototypes *****************************/
#ifndef __linux__
int XDoimgproc_Initialize(XDoimgproc *InstancePtr, u16 DeviceId);
XDoimgproc_Config* XDoimgproc_LookupConfig(u16 DeviceId);
int XDoimgproc_CfgInitialize(XDoimgproc *InstancePtr, XDoimgproc_Config *ConfigPtr);
#else
int XDoimgproc_Initialize(XDoimgproc *InstancePtr, const char* InstanceName);
int XDoimgproc_Release(XDoimgproc *InstancePtr);
#endif

void XDoimgproc_Start(XDoimgproc *InstancePtr);
u32 XDoimgproc_IsDone(XDoimgproc *InstancePtr);
u32 XDoimgproc_IsIdle(XDoimgproc *InstancePtr);
u32 XDoimgproc_IsReady(XDoimgproc *InstancePtr);
void XDoimgproc_EnableAutoRestart(XDoimgproc *InstancePtr);
void XDoimgproc_DisableAutoRestart(XDoimgproc *InstancePtr);

void XDoimgproc_Set_operation(XDoimgproc *InstancePtr, u32 Data);
u32 XDoimgproc_Get_operation(XDoimgproc *InstancePtr);
u32 XDoimgproc_Get_kernel_BaseAddress(XDoimgproc *InstancePtr);
u32 XDoimgproc_Get_kernel_HighAddress(XDoimgproc *InstancePtr);
u32 XDoimgproc_Get_kernel_TotalBytes(XDoimgproc *InstancePtr);
u32 XDoimgproc_Get_kernel_BitWidth(XDoimgproc *InstancePtr);
u32 XDoimgproc_Get_kernel_Depth(XDoimgproc *InstancePtr);
u32 XDoimgproc_Write_kernel_Words(XDoimgproc *InstancePtr, int offset, int *data, int length);
u32 XDoimgproc_Read_kernel_Words(XDoimgproc *InstancePtr, int offset, int *data, int length);
u32 XDoimgproc_Write_kernel_Bytes(XDoimgproc *InstancePtr, int offset, char *data, int length);
u32 XDoimgproc_Read_kernel_Bytes(XDoimgproc *InstancePtr, int offset, char *data, int length);

void XDoimgproc_InterruptGlobalEnable(XDoimgproc *InstancePtr);
void XDoimgproc_InterruptGlobalDisable(XDoimgproc *InstancePtr);
void XDoimgproc_InterruptEnable(XDoimgproc *InstancePtr, u32 Mask);
void XDoimgproc_InterruptDisable(XDoimgproc *InstancePtr, u32 Mask);
void XDoimgproc_InterruptClear(XDoimgproc *InstancePtr, u32 Mask);
u32 XDoimgproc_InterruptGetEnabled(XDoimgproc *InstancePtr);
u32 XDoimgproc_InterruptGetStatus(XDoimgproc *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
