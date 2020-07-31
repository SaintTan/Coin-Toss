#pragma once
#include "QueData.h"
#include "Stock.h"
#include <vector>
#include <iostream>

namespace Data {
	class DataManager {
	private:
		std::vector<Stock::Stock> dm_stocks;
		QueData dm_quedata;
	public:
		DataManager();
		~DataManager();
	protected:
	};
}


