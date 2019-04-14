// ==============================================================
// File generated on Thu Apr 11 00:03:33 EDT 2019
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#include "xparameters.h"
#include "xdoimgproc.h"

extern XDoimgproc_Config XDoimgproc_ConfigTable[];

XDoimgproc_Config *XDoimgproc_LookupConfig(u16 DeviceId) {
	XDoimgproc_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XDOIMGPROC_NUM_INSTANCES; Index++) {
		if (XDoimgproc_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XDoimgproc_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XDoimgproc_Initialize(XDoimgproc *InstancePtr, u16 DeviceId) {
	XDoimgproc_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XDoimgproc_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XDoimgproc_CfgInitialize(InstancePtr, ConfigPtr);
}

#endif

