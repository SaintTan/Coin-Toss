#pragma once
#include <chrono>

class IDManagement {
private:
	static char currentID;
	static const std::chrono::milliseconds intervals[5];
public:
	IDManagement();
	static char getNewID();
	static std::chrono::milliseconds getNewIntervals();
};

class CandleStick{
private:
	char cs_candleID;
	float cs_maxPrice, cs_minPrice, cs_openPrice, cs_closePrice;
	std::chrono::milliseconds cs_startTime;
	std::chrono::milliseconds cs_timeInterval;
public:
	CandleStick(); 
	void updateCandleStick(float, float); //maxPrice, minPrice
protected:
	static std::chrono::milliseconds getCurrentTime();
};


