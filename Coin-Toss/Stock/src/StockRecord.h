#pragma once
#include "MarketQue.h"

namespace Stock {
	template <size_t size>
	class StockRecord {
	private:
		MarketQue<size> sr_topPrevPrices;
	public:
		StockRecord(); //cs_Interval
		void updateStockRecord(MarketQue<size>& topPrev_prices);
		~StockRecord();
	protected:
	};
}


