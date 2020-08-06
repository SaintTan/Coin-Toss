#pragma once
#include "QueData.h"
#include "Stock.h"
#include "Preprocess.h"
#include <vector>

static unsigned int getTotalVol(const Stock::StockQue& stockque); //calculates the total amount of volume inside the stock que

namespace Data {
	class DataManager {
	private:
		std::vector<Stock::StockQue> dm_stockques; //holds stockque data
		QueData dm_quedata; //deals with update of stockque data
		unsigned int dm_stocksize; //stores size of stocks
	public:
		DataManager(std::vector<Stock::Stock>&); //stocks 
		void updateData(std::vector<Stock::Stock>&); //stocks : updates data
		~DataManager();
	protected:
	};
}


