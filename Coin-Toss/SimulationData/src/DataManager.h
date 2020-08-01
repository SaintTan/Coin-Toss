#pragma once
#include "QueData.h"
#include "Stock.h"
#include "Preprocess.h"
#include <vector>

static unsigned int getTotalVol(const Stock::StockQue& stockque);

namespace Data {
	class DataManager {
	private:
		std::vector<Stock::StockQue> dm_stockques;
		QueData dm_quedata;
		unsigned int dm_stocksize;
	public:
		DataManager(std::vector<Stock::Stock>&);
		void updateData(std::vector<Stock::Stock>& const stocks);
		~DataManager();
	protected:
	};
}


