#pragma once
#include "MarketQue.h"

namespace Stock {
	class StockRecord {
	private:
		MarketQue sr_topPrevPrices;
	public:
		StockRecord(int cs_size); //cs_Interval
		void updateStockRecord(MarketQue& topPrev_prices);
		~StockRecord();
	protected:
	};
}


