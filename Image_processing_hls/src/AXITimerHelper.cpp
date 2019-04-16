/*
 * AXITimerHelper.cpp
 *
 *  Created on: Apr 15, 2019
 *      Author: anhnguyen
 */

#include "AXITimerHelper.h"

AXITimerHelper::AXITimerHelper() {
	//Initialize Timer hardware
	XTmrCtr_Initialize(&m_AxiTimer, XPAR_TMRCTR_0_DEVICE_ID);

	//Get the clocks in seconds
	m_timerClockFreq = (double) XPAR_AXI_TIMER_0_CLOCK_FREQ_HZ;
	m_clockPeriodSeconds = (double)1/m_timerClockFreq;
}

AXITimerHelper::~AXITimerHelper() {
	// TODO Auto-generated destructor stub
}

unsigned int AXITimerHelper::getElapsedTicks(){
	return m_tickCounter2 - m_tickCounter1;
}

unsigned int AXITimerHelper::startTimer(){
	XTmrCtr_Reset(&m_AxiTimer, 0);
	m_tickCounter1 = XTmrCtr_GetValue(&m_AxiTimer, 0);
	XTmrCtr_Start(&m_AxiTimer, 0);
	return m_tickCounter1;
}

unsigned int AXITimerHelper::stopTimer(){
	XTmrCtr_Stop(&m_AxiTimer,0);
	m_tickCounter2 = XTmrCtr_GetValue(&m_AxiTimer, 0);
	return m_tickCounter2 - m_tickCounter1;
}

double AXITimerHelper::getElapsedTimerInSeconds(){
	double elapsedTimeInSeconds = (double)(m_tickCounter2 - m_tickCounter1);
	return elapsedTimeInSeconds;
}

double AXITimerHelper::getClockPeriod(){
	return m_clockPeriodSeconds;
}

double AXITimerHelper::getTimerClockFreq(){
	return m_timerClockFreq;
}



