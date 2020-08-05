#include "StockRecord.h"

Stock::StockRecord::StockRecord(int cs_size):sr_topPrevPrices(StockQue(cs_size)) {};

void Stock::StockRecord::updateStockRecord(StockQue& topPrevPrices) {
	sr_topPrevPrices = topPrevPrices;
}

Stock::StockRecord::~StockRecord() {};