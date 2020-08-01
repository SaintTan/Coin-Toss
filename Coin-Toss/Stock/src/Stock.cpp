#include "Stock.h"

Stock::Stock::Stock(const std::string& stockID, StockQue& topPrices, std::vector<unsigned int>& csInterval)
	:s_stockID(stockID), s_topCur(&topPrices), s_stockRecord(StockRecord(topPrices.mq_size)), s_totalVol(getTotalVol(topPrices)) {
	s_candleSticks.reserve(csInterval.size());
	for (unsigned int i = 0; i < csInterval.size(); i++) {
		s_candleSticks.emplace_back(topPrices.mq_topPrice_S[0], topPrices.mq_topPrice_B[0], csInterval[i]);
	}
};

void Stock::Stock::updateStock() {
	s_totalVol = getTotalVol(*s_topCur);
	s_stockRecord.updateStockRecord(*s_topCur);
	for (unsigned int i = 0; i < s_candleSticks.size(); i++) {
		s_candleSticks[i].updateCandleStick((s_topCur->mq_topPrice_B)[0], (s_topCur->mq_topPrice_S)[0]);
	}
}

unsigned int Stock::Stock::getTotalVol(const StockQue& stockque) const {
	unsigned int totalVol = 0;
	for (unsigned int i = 0; i < stockque.mq_size; i++) {
		totalVol += stockque.mq_topVol_B[i] + stockque.mq_topVol_S[i];
	}
	return totalVol;
}

Stock::Stock::~Stock() {};