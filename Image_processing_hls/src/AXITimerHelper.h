/*
 * AXITimerHelper.h
 *
 *  Created on: Apr 15, 2019
 *      Author: anhnguyen
 */

#include<xil_types.h>
#include<xtmrctr.h>
#include<xparameters.h>

#ifndef SRC_AXITIMERHELPER_H_
#define SRC_AXITIMERHELPER_H_

class AXITimerHelper {
public:
	AXITimerHelper();
	virtual ~AXITimerHelper();
	unsigned int getElapsedTicks();
	double getElapsedTimerInSeconds();
	unsigned int startTimer();
	unsigned int stopTimer();
	double getClockPeriod();
	double getTimerClockFreq();

private:
	XTmrCtr m_AxiTimer;
	unsigned int m_tickCounter1;
	unsigned int m_tickCounter2;
	double m_clockPeriodSeconds;
	double m_timerClockFreq;
};

#endif /* SRC_AXITIMERHELPER_H_ */
