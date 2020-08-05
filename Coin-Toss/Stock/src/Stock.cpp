#include "Stock.h"

Stock::Stock::Stock(const std::wstring& stockID, StockQue& topPrices, std::vector<unsigned int>& csInterval, unsigned int totalVol)
	:s_stockID(stockID), s_topCur(&topPrices), s_stockRecord(StockRecord(topPrices.mq_size)), s_totalVol(totalVol) {
	s_candleSticks.reserve(csInterval.size());
	for (unsigned int i = 0; i < csInterval.size(); i++) {
		s_candleSticks.emplace_back(topPrices.mq_topPrice_S[0], topPrices.mq_topPrice_B[0], csInterval[i]);
	}
};

void Stock::Stock::updateStockQue(unsigned int totalVol) {
	s_totalVol = totalVol;
	s_stockRecord.updateStockRecord(*s_topCur);
	for (unsigned int i = 0; i < s_candleSticks.size(); i++) {
		s_candleSticks[i].updateCandleStick((s_topCur->mq_topPrice_B)[0], (s_topCur->mq_topPrice_S)[0]);
	}
}

std::wstring Stock::Stock::get_stockID() const {
	return s_stockID;
}



Stock::Stock::~Stock() {};