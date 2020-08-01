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
		dm_quedata.initializeData(i, dm_stockques[i]);
	}
	//get time intervals
	std::vector<unsigned int> intervals = {1000,2500, 10000, 25000, 50000};

	//reserving for stock innitialization
	stocks.reserve(stock_ids.size());

	for (unsigned int i = 0; i < dm_stocksize; i++) {
		std::string str(stock_ids[i].begin(), stock_ids[i].end());
		stocks.emplace_back(Stock::Stock(str, dm_stockques[i], intervals));
	}
	return;
}

void Data::DataManager::updateData(std::vector<Stock::Stock>& const stocks){
	for (auto it = stocks.begin(); it != stocks.end(); it++) {
		it->updateStock();
	}
	for (unsigned int i = 0; i < dm_stocksize; i++) {
		dm_quedata.updateData(i, dm_stockques[i]);
	}
	return;
}



Data::DataManager::~DataManager(){}
