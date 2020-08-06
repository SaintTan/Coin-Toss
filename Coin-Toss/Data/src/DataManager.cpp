#include "DataManager.h"

Data::DataManager::DataManager(std::vector<Stock::Stock>& stocks):dm_quedata(QueData()), dm_stocksize(0) {
	std::vector<std::wstring> stock_ids;
	//get ids
	dm_quedata.getFileNames(stock_ids);
	dm_stocksize = stock_ids.size();
	//get stock ques
	dm_stockques.reserve(dm_stocksize);
	for (unsigned int i = 0; i < dm_stocksize; i++) {
		dm_stockques.emplace_back(Stock::StockQue(3));
		for (unsigned int j = 0; j < dm_stockques[i].mq_size; j++) {
			dm_stockques[i].mq_topPrice_B.emplace_back();
			dm_stockques[i].mq_topPrice_S.emplace_back();
			dm_stockques[i].mq_topVol_B.emplace_back();
			dm_stockques[i].mq_topVol_S.emplace_back();
		}
		dm_quedata.updateData(i, dm_stockques[i]);
	}
	//get time intervals
	std::vector<unsigned int> intervals = {1000,2500, 10000, 25000, 50000};

	//reserving for stock innitialization
	stocks.reserve(stock_ids.size());

	for (unsigned int i = 0; i < dm_stocksize; i++) {
		stocks.emplace_back(Stock::Stock(stock_ids[i], dm_stockques[i], intervals, getTotalVol(dm_stockques[i])));
	}
	return;
}

void Data::DataManager::updateData(std::vector<Stock::Stock>& stocks){
	for (unsigned int i = 0; i < dm_stocksize; i++) {
		stocks[i].updateStockQue(getTotalVol(dm_stockques[i]));
		dm_quedata.updateData(i, dm_stockques[i]);
	}
	return;
}


Data::DataManager::~DataManager(){}

static unsigned int getTotalVol(const Stock::StockQue& stockque) {
	unsigned int totalVol = 0;
	for (unsigned int i = 0; i < stockque.mq_size; i++) {
		totalVol += stockque.mq_topVol_B[i] + stockque.mq_topVol_S[i];
	}
	return totalVol;
}