#include "StockRecord.h"
#include <iostream>

Stock::StockRecord::StockRecord(int cs_size):sr_topPrevPrices(StockQue(cs_size)) {};

Stock::StockQue* Stock::StockRecord::getStockQue(){
	return &sr_topPrevPrices;
}

//updates stockque
void Stock::StockRecord::updateStockRecord(const StockQue& topPrevPrices) {
	sr_topPrevPrices = topPrevPrices;
}

Stock::StockRecord::~StockRecord() {};