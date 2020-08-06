#pragma once
#include "CandleStick.h"
#include "StockRecord.h"
#include "StockQue.h"
#include <string>
#include <vector>

namespace Stock {
	class Stock {
	private:
		std::wstring s_stockID;
		StockQue* s_topCur;
		StockRecord s_stockRecord;
		std::vector<CandleStick> s_candleSticks;
		unsigned int s_totalVol;
	private:
	public:
		Stock(const std::wstring&, StockQue&, std::vector<unsigned int>&, unsigned int); //stockID, s_topCur, cs_interval, total_vol
		void updateStockQue(unsigned int);
		std::wstring get_stockID() const;
		~Stock();
	protected:
	};
}