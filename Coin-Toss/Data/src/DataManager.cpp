#include "DataManager.h"

Data::DataManager::DataManager(std::vector<Stock::Stock*>& stocks):dm_stocksize(0) {
	std::vector<std::wstring> stock_ids;

	//get ids
	QueData::getFileNames(stock_ids);

	//get number of stuck
	dm_stocksize = stock_ids.size();

	//initializing QueData
	dm_quedata = new QueData(stock_ids.size());
	
	//get time intervals
	std::vector<uint32_t> intervals = {100};

	//reserving size for stocks
	stocks.reserve(stock_ids.size());

	//adding in stock elements
	for (uint32_t i = 0; i < dm_stocksize; i++) {
		Stock::StockQue* stockque = dm_quedata->getStockQue(i);
		stocks.emplace_back(new Stock::Stock(stock_ids[i], *stockque, intervals));
	}
	return;
}

//updates data
void Data::DataManager::updateData(std::vector<Stock::Stock*>& stocks){
	//updates stock before data update
	for (auto stock = stocks.begin(); stock != stocks.end(); stock++) {
		(*stock)->updateStockQue1();
	}
	//update data
	dm_quedata->updateData();
	//updates stock after data update
	for (auto stock = stocks.begin(); stock != stocks.end(); stock++) {
		(*stock)->updateStockQue2();
	}
	return;
}


Data::DataManager::~DataManager(){
	delete dm_quedata;
}

