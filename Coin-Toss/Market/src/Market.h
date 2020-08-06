#pragma once
#include "Stock.h"
#include "DataManager.h"
#include "Broker.h"
#include <string>
#include <vector>

namespace Market {
	class Market {
	private:
		std::string m_marketID;
		std::vector<Stock::Stock> m_stocks;
		Data::DataManager m_datamanager;
		std::vector<Broker> m_brokers;
	public:
		Market(const std::string&);
		void updateStock();
		void updateBroker();
		~Market();
	protected:
	};
}

