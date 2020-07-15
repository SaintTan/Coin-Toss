#include "StockRecord.h"

template <size_t size>
Stock::StockRecord<size>::StockRecord()
	:sr_topPrevPrices(MarketQue<size>{}) {};

template <size_t size>
void Stock::StockRecord<size>::updateStockRecord(MarketQue<size>& topPrevPrices) {
	sr_topPrevPrices = topPrevPrices;
}

template<size_t size>
Stock::StockRecord<size>::~StockRecord() {};