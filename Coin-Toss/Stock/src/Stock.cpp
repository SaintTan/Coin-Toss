#include "Stock.h"
#include <iostream>

Stock::Stock::Stock(const std::wstring& stockID, StockQue& topPrices, std::vector<uint32_t>& csInterval)
	:s_stockID(stockID), s_topCur(&topPrices), s_stockRecord(StockRecord(topPrices.mq_size)), s_totalVol(getTotalVol(topPrices)), 
	s_candleStickManager(CandleStickManager(topPrices.mq_topPrice_S[0], topPrices.mq_topPrice_B[0], 5, csInterval)) {};

//updates stockRecordd and candlesticks
void Stock::Stock::updateStockQue1() {
	s_stockRecord.updateStockRecord(*s_topCur);
}

//updates the total volume
void Stock::Stock::updateStockQue2() {
	s_totalVol = getTotalVol(*s_topCur);
	s_candleStickManager.updateCandleSticks(*s_topCur, *s_stockRecord.getStockQue());
}

//returns stockque
const Stock::StockQue* Stock::Stock::getStockQue() const{
	return s_topCur;
}

const Stock::StockRecord* Stock::Stock::getStockRecord() const{
	return &s_stockRecord;
}

//returns stockID
std::wstring Stock::Stock::get_stockID() const {
	return s_stockID;
}

//calculates the total amount of volume inside the stock que
static uint32_t getTotalVol(const Stock::StockQue& stockque) {
	uint32_t totalVol = 0;
	//goes through elements and add them together
	for (uint32_t i = 0; i < stockque.mq_size; i++) {
		totalVol += stockque.mq_topVol_B[i] + stockque.mq_topVol_S[i];
	}
	return totalVol;
}

Stock::Stock::~Stock() {};