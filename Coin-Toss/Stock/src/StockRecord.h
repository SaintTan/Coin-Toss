#pragma once
#include "StockQue.h"

namespace Stock {
	class StockRecord {
	private:
		StockQue sr_topPrevPrices; //stockque
	public:
		StockRecord(int); //cs_Interval
		const StockQue* getStockQue() const; //return stockque
		void updateStockRecord(const StockQue&); //stockque : updates stockRecord 
		~StockRecord();
	protected:
	};
}


