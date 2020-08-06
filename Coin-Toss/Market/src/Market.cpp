#include "Market.h"

Market::Market::Market(const std::string& marketID):m_marketID(marketID),m_stocks(),m_datamanager(Data::DataManager(m_stocks)), m_brokers() {
	m_brokers.reserve(1);
	std::string tempID("001");
	m_brokers.emplace_back(new Broker(tempID, 1, m_stocks));
}

void Market::Market::updateStock() {
	m_datamanager.updateData(m_stocks);
	updateBroker();
}

void Market::Market::updateBroker() {
	for (auto broker = m_brokers.begin(); broker != m_brokers.end(); broker++) {
		(*broker)->receiveUpdate();
	}
}

Market::Market::~Market() {}