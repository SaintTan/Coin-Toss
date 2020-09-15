#pragma once
#include "StockQue.h"

struct HighLowPrice {
private:
public:
	bool changes;
	float highestPrice;
	float lowestPrice;
	HighLowPrice():highestPrice(0), lowestPrice(0), changes(true) {}
protected:
};

static HighLowPrice traded_price(const Stock::StockQue& current, const Stock::StockQue& previous); // finds the lowest and highest price difference

namespace Stock {
	class CandleStick {
	private:
		float cs_maxPrice, cs_minPrice, cs_openPrice, cs_closePrice; //prices of stock
	public:
		CandleStick();
		CandleStick(float); //opening price
		CandleStick(float, float); //maxPrice, minPrice
		void updateCandleStick(const StockQue&, const StockQue&); //maxPrice, minPrice : updates candlestick *NEEDS REVISION
		~CandleStick();
	protected:
	};
};




