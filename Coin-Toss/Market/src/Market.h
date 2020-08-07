#pragma once
#include "Stock.h"
#include "DataManager.h"
#include "Broker.h"
#include <string>
#include <vector>

namespace Market {
	class Market {
	private:
		std::string m_marketID; //ID for market
		std::vector<Stock::Stock> m_stocks; //stores stocks 
		Data::DataManager m_datamanager; //data manager 
		std::vector<Broker*> m_brokers; //stores pointers to brokers
	public:
		Market(const std::string&); //marketIID
		void updateStock(); //updates data of stocks
		void updateBroker(); //informs brokers of data update
		~Market();
	protected:
	};
}

