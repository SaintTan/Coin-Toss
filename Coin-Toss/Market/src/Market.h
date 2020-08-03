#pragma once
#include "Stock.h"
#include "DataManager.h"
#include "TraderStockPage.h"
#include <string>
#include <vector>

namespace Market {
	class Market {
	private:
		std::string m_marketID;
		std::vector<Stock::Stock> m_stocks;
		Data::DataManager m_datamanager;
		std::vector<Market> m_brokers;
		

	public:
		Market(const std::string&);
		void updateStock();
		~Market();
	protected:
	};
}

