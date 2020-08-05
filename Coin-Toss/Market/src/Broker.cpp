#include "Broker.h"

Market::Broker::Broker(const std::string& brokerID, unsigned int traderNum, std::vector<Stock::Stock>& stocks): b_brokerID(brokerID) {
	b_traders.reserve(traderNum);
	for (unsigned int i = 0; i < traderNum; i++) {
		b_traders.emplace_back(Market::Trader(stocks, *this));
	}
}

Market::Broker::~Broker() {}