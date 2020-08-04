#include "Market.h"

Market::Market::Market(const std::string& marketID):m_marketID(marketID),m_stocks(),m_datamanager(Data::DataManager(m_stocks)), m_brokers() {
	m_brokers.reserve(1);
	m_brokers.emplace_back(Broker("001", 1, m_stocks));
}

void Market::Market::updateStock() {
	m_datamanager.updateData(m_stocks);
}

Market::Market::~Market() {}