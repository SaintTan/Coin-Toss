#include "Stock.h"

template <size_t size, size_t size_cs>
Stock::Stock<size, size_cs>::Stock(const std::string& stockID, MarketQue<size>& topPrices, std::array<unsigned int, size_cs>& csInterval, unsigned int totalVol)
	:s_stockID(stockID), s_topCurPrices(&topPrices), s_stockRecord(StockRecord<size>()), s_totalVol(totalVol), s_candleSticks(std::array<CandleStick, size_cs>{}) {
	for (unsigned int i = 0; i < csInterval.size(); i++) {
		s_candleSticks[i].setInterval(csInterval[i]);
	}
};

template<size_t size, size_t size_cs>
void Stock::Stock<size, size_cs>::updateStock(int totalVol) {
	s_totalVol = totalVol;
//	s_stockRecord.updateStockRecord(*s_topCurPrice_B, *s_topCurPrice_S, *s_topCurVol_B, *s_topCurVol_S);
	for (unsigned int i = 0; i < s_candleSticks.size(); i++) {
//		s_candleSticks[i].updateCandleStick((*s_topCurPrice_S)[0], (*s_topCurPrice_B)[0]);
	}
}

template<size_t size, size_t size_cs>
Stock::Stock<size, size_cs>::~Stock() {};

//linking error
template class Stock::Stock<3, 5>;
template class Stock::Stock<5, 5>;