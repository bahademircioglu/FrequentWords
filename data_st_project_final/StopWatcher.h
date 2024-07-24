#pragma once
#include "Headers.h"

class StopWatcher
{
private:
	clock_t startTime;
public:
	StopWatcher();
	clock_t getCurrentTimeSecond();
	clock_t getCurrentTimeRest();
	~StopWatcher();
};

