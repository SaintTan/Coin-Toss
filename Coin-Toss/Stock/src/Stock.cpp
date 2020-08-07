#include "Stock.h"

Stock::Stock::Stock(const std::wstring& stockID, StockQue& topPrices, std::vector<unsigned int>& csInterval)
	:s_stockID(stockID), s_topCur(&topPrices), s_stockRecord(StockRecord(topPrices.mq_size)), s_totalVol(getTotalVol(topPrices)) {
	s_candleSticks.reserve(csInterval.size());
	for (unsigned int i = 0; i < csInterval.size(); i++) {
		s_candleSticks.emplace_back(topPrices.mq_topPrice_S[0], topPrices.mq_topPrice_B[0], csInterval[i]);
	}
};

//updates stockRecordd and candlesticks
void Stock::Stock::updateStockQue1() {
	s_stockRecord.updateStockRecord(*s_topCur);
	for (unsigned int i = 0; i < s_candleSticks.size(); i++) {
		s_candleSticks[i].updateCandleStick((s_topCur->mq_topPrice_B)[0], (s_topCur->mq_topPrice_S)[0]);
	}
}

//updates the total volume
void Stock::Stock::updateStockQue2() {
	s_totalVol = getTotalVol(*s_topCur);
}

//returns stockque
Stock::StockQue* Stock::Stock::getStockQue() const {
	return s_topCur;
}

//returns stockID
std::wstring Stock::Stock::get_stockID() const {
	return s_stockID;
}

//calculates the total amount of volume inside the stock que
static unsigned int getTotalVol(const Stock::StockQue& stockque) {
	unsigned int totalVol = 0;
	//goes through elements and add them together
	for (unsigned int i = 0; i < stockque.mq_size; i++) {
		totalVol += stockque.mq_topVol_B[i] + stockque.mq_topVol_S[i];
	}
	return totalVol;
}



Stock::Stock::~Stock() {};