#pragma once
#include "QueData.h"
#include "Stock.h"
#include "Preprocess.h"
#include <vector>

namespace Data {
	class DataManager {
	private:
		QueData* dm_quedata; //deals with update of stockque data
		unsigned int dm_stocksize; //stores size of stocks
	public:
		DataManager(std::vector<Stock::Stock*>&); //stocks 
		void updateData(std::vector<Stock::Stock*>&); //stocks : updates data
		~DataManager();
	protected:
	};
}


