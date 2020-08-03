#include "Market.h"

Market::Market::Market(const std::string& marketID):m_marketID(marketID),m_stocks(),m_datamanager(Data::DataManager(m_stocks)), m_brokers() {}

void Market::Market::updateStock() {
	m_datamanager.updateData(m_stocks);
}