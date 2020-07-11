#include "CandleStick.h"
#include <iostream>

static const int ID = 97;

char Stock::IDManagement::currentID = ID;
const std::chrono::milliseconds Stock::IDManagement::intervals[5] = {std::chrono::milliseconds(1000), std::chrono::milliseconds(5000), 
	std::chrono::milliseconds(10000), std::chrono::milliseconds(60000), std::chrono::milliseconds(300000) }; // 1 sec, 5 sec, 10 sec, 1 min , 5 min

Stock::IDManagement::IDManagement() {}

char Stock::IDManagement::getNewID() {
	return (char)currentID++;
}

std::chrono::milliseconds Stock::IDManagement::getNewIntervals() {
	return intervals[currentID - ID - 1];
}

Stock::CandleStick::CandleStick(float max_price, float min_price)
	:cs_maxPrice(max_price), cs_minPrice(min_price), cs_openPrice(0), cs_closePrice(max_price),
	cs_timeInterval(IDManagement::getNewIntervals()), cs_startTime(CandleStick::getCurrentTime()), cs_candleID(IDManagement::getNewID()){
}

void Stock::CandleStick::updateCandleStick(float max_price, float min_price) {
	std::chrono::milliseconds currentTime = CandleStick::getCurrentTime();
	if ((currentTime.count() - cs_startTime.count()) > cs_timeInterval.count()) {
		cs_startTime = currentTime;
		cs_maxPrice = max_price;
		cs_minPrice = min_price;
		cs_openPrice = cs_closePrice;
		cs_closePrice = max_price;
		return;
	}
	else {
		if (cs_maxPrice < max_price) {
			cs_maxPrice = max_price;
		}
		if (cs_minPrice > min_price) {
			cs_minPrice = min_price;
		}
		return;
	}
}

std::chrono::milliseconds Stock::CandleStick::getCurrentTime() {
	std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
	auto now_ms = std::chrono::time_point_cast<std::chrono::milliseconds>(now);
	return now_ms.time_since_epoch();
}