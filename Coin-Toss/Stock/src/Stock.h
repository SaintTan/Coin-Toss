#pragma once
#include "CandleStick.h"
#include "StockRecord.h"
#include "StockQue.h"
#include <string>
#include <vector>

namespace Stock {
	class Stock {
	private:
		std::wstring s_stockID; //ID of stock - also stock symbol
		StockQue* s_topCur; //stockque
		StockRecord s_stockRecord; //previous stockrecord
		std::vector<CandleStick> s_candleSticks; //candle stick with different intervals
		unsigned int s_totalVol; //total volume of stockque
	private:
	public:
		Stock(const std::wstring&, StockQue&, std::vector<unsigned int>&, unsigned int); //stockID, s_topCur, cs_interval, total_vol
		void updateStockQue(unsigned int); //totalVol : updates stockRecordd and candlesticks
		std::wstring get_stockID() const; //returns stockID
		~Stock();
	protected:
	};
}