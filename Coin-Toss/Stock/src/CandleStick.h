#pragma once
#include "StockQue.h"
#include <iostream>

struct HighLowPrice {
private:
public:
	float highestPrice;
	float lowestPrice;
	HighLowPrice(float hPrice, float lPrice):highestPrice(hPrice), lowestPrice(lPrice) {}
protected:
};

static HighLowPrice traded_price(const Stock::StockQue& current, const Stock::StockQue& previous); // finds the lowest and highest price difference

namespace Stock {
	class CandleStick {
	private:
		float cs_maxPrice, cs_minPrice, cs_openPrice, cs_closePrice; //prices of stock
		int cs_tickTime; //current tick
		int cs_tickInterval; //tick intervals
	public:
		CandleStick();
		CandleStick(float, float , int); //maxPrice, minPrice, tickInterval
		void updateCandleStick(const StockQue&, const StockQue&); //maxPrice, minPrice : updates candlestick *NEEDS REVISION
		~CandleStick();
	protected:
	};
};




