#include "Stock.h"
#include <iostream>

template <size_t size>
Stock::Stock<size>::Stock(const std::string& stockID, MarketQue<size>& topPrices, std::vector<unsigned int>& csInterval, unsigned int totalVol)
	:s_stockID(stockID), s_topCur(&topPrices), s_stockRecord(StockRecord<size>()), s_totalVol(totalVol) {
	s_candleSticks.reserve(csInterval.size());
	for (unsigned int i = 0; i < csInterval.size(); i++) {
		s_candleSticks.emplace_back(topPrices.mq_topPrice_S[0], topPrices.mq_topPrice_B[0], csInterval[i]);
	}
};

template<size_t size>
void Stock::Stock<size>::updateStock(int totalVol) {
	s_totalVol = totalVol;
	s_stockRecord.updateStockRecord(*s_topCur);
	for (unsigned int i = 0; i < s_candleSticks.size(); i++) {
		s_candleSticks[i].updateCandleStick((s_topCur->mq_topPrice_B)[0], (s_topCur->mq_topPrice_S)[0]);
	}
}

template<size_t size>
Stock::Stock<size>::~Stock() {};

//linking error
template class Stock::Stock<3>;
template class Stock::Stock<5>;