#include "DataManager.h"

Data::DataManager::DataManager():dm_quedata(QueData()), dm_stocks() {
	std::vector<std::wstring> stock_ids;
	dm_quedata.getFileNames(stock_ids);
	for (auto stock_id = stock_ids.begin(); stock_id != stock_ids.end(); stock_id++) {
		std::wcout << *stock_id << std::endl;
	}
}

Data::DataManager::~DataManager(){}