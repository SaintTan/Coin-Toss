#include "CandleStick.h"
#include <iostream>

static const int ID = 97;

char Stock::IDManagement::currentID = ID;


Stock::IDManagement::IDManagement() {}

char Stock::IDManagement::getNewID() {
	return (char)currentID++;
};

Stock::CandleStick::CandleStick() :cs_maxPrice(0), cs_minPrice(0), cs_openPrice(0), cs_closePrice(0),
cs_tickInterval(0), cs_tickTime(0), cs_candleID(IDManagement::getNewID()) {}

Stock::CandleStick::CandleStick(int interval) : cs_maxPrice(0), cs_minPrice(0), cs_openPrice(0), cs_closePrice(0),
cs_tickInterval(interval), cs_tickTime(0), cs_candleID(IDManagement::getNewID()) {}

void Stock::CandleStick::setInterval(int tickInterval){
	cs_tickInterval = tickInterval;
};

void Stock::CandleStick::updateCandleStick(float max_price, float min_price) {
	if (cs_tickTime > cs_tickInterval) {
		cs_tickTime = 1;
		cs_maxPrice = max_price;
		cs_minPrice = min_price;
		cs_openPrice = cs_closePrice;
		cs_closePrice = max_price;
	}
	else {
		if (cs_maxPrice < max_price) {
			cs_maxPrice = max_price;
		}
		if (cs_minPrice > min_price) {
			cs_minPrice = min_price;
		}
	}
	cs_tickTime++;
	return;
};

Stock::CandleStick::~CandleStick() {}