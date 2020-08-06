#pragma once
#include "StockQue.h"

namespace Stock {
	class StockRecord {
	private:
		StockQue sr_topPrevPrices;
	public:
		StockRecord(int); //cs_Interval
		void updateStockRecord(StockQue&);
		~StockRecord();
	protected:
	};
}


