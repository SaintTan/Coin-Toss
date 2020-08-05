#include "Market.h"

Market::Market::Market(std::string& marketID):m_marketID(marketID),m_stocks(),m_datamanager(Data::DataManager(m_stocks)), m_brokers() {
	m_brokers.reserve(1);
	std::string tempID("001");
	m_brokers.emplace_back(Broker(tempID, 1, m_stocks));
}

void Market::Market::updateStock() {
	m_datamanager.updateData(m_stocks);
}

Market::Market::~Market() {}