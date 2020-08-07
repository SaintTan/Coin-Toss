#include "CandleStick.h"

Stock::CandleStick::CandleStick() :cs_maxPrice(0), cs_minPrice(0), cs_openPrice(0), cs_closePrice(0),
cs_tickInterval(0), cs_tickTime(0) {}

Stock::CandleStick::CandleStick(float max_price, float min_price,int interval) : cs_maxPrice(max_price), cs_minPrice(min_price), cs_openPrice(0), cs_closePrice(max_price),
cs_tickInterval(interval), cs_tickTime(0) {}

//maxPrice, minPrice : updates candlestick *NEEDS REVISION
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