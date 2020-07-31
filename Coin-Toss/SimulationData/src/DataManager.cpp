#include "DataManager.h"

Data::DataManager::DataManager(std::vector<Stock::Stock>& stocks):dm_quedata(QueData()), dm_stocksize(0) {
	std::vector<std::wstring> stock_ids;
	dm_quedata.getFileNames(stock_ids);
	dm_stocksize = stock_ids.size();

	dm_stockques.reserve(dm_stocksize);
	for (unsigned int i = 0; i < dm_stocksize; i++) {
		dm_stockques.emplace_back(Stock::StockQue(3));
		dm_quedata.initializeData(i, dm_stockques[i]);
		std::cout << dm_stockques[i].mq_topPrice_B[0] << std::endl;
	}
	
	std::vector<unsigned int> intervals = {1000,10000,20000};
	unsigned int totalVol = 0;

	stocks.reserve(stock_ids.size());

	for (unsigned int i = 0; i < dm_stocksize; i++) {
		
		std::string str(stock_ids[i].begin(), stock_ids[i].end());
		stocks.emplace_back(Stock::Stock(str, dm_stockques[i], intervals, totalVol));
	}
}

Data::DataManager::~DataManager(){}