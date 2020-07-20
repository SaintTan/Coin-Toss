#include "StockRecord.h"

Stock::StockRecord::StockRecord(int cs_size)
	:sr_topPrevPrices(MarketQue(cs_size)) {};

void Stock::StockRecord::updateStockRecord(MarketQue& topPrevPrices) {
	sr_topPrevPrices = topPrevPrices;
}

Stock::StockRecord::~StockRecord() {};