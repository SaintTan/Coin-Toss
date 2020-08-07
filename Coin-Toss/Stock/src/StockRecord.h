#pragma once
#include "StockQue.h"

namespace Stock {
	class StockRecord {
	private:
		StockQue sr_topPrevPrices; //stockque
	public:
		StockRecord(int); //cs_Interval
		void updateStockRecord(const StockQue&); //update stockque
		~StockRecord();
	protected:
	};
}


