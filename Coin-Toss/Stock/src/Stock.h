#pragma once
#include "CandleStick.h"
#include "StockRecord.h"
#include "MarketQue.h"
#include <string>
#include <vector>
#include <array>

namespace Stock {
	template <size_t size>
	class Stock {
	private:
		std::string s_stockID;
		MarketQue<size>* s_topCur;
		StockRecord<size> s_stockRecord;
		std::vector<CandleStick> s_candleSticks;
		unsigned int s_totalVol;
	public:
		Stock(const std::string&, MarketQue<size>&, std::vector<unsigned int>&, unsigned int); //stockID, s_topCurPrice_B, s_topCurPrice_S, s_topCurVol_B, s_topCurVol_S, cs_interval, total_vol
		void updateStock(int);
		~Stock();
	protected:
	};
}


#include "StockRecord.cpp"