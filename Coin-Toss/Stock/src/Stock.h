#pragma once
#include "CandleStick.h"
#include "StockRecord.h"
#include "StockQue.h"
#include <string>
#include <vector>

namespace Stock {
	class Stock {
	private:
		std::string s_stockID;
		StockQue* s_topCur;
		StockRecord s_stockRecord;
		std::vector<CandleStick> s_candleSticks;
		unsigned int s_totalVol;
	private:
		unsigned int getTotalVol(const StockQue&) const;
	public:
		Stock(const std::string&, StockQue&, std::vector<unsigned int>&); //stockID, s_topCurPrice_B, s_topCurPrice_S, s_topCurVol_B, s_topCurVol_S, cs_interval, total_vol
		void updateStock();
		~Stock();
	protected:
	};
}