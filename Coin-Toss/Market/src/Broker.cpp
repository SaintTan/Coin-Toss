#include "Broker.h"

Market::Broker::Broker(const std::string& brokerID, unsigned int traderNum, std::vector<Stock::Stock>& stocks): b_brokerID(brokerID) {
	b_traders.reserve(traderNum);
	for (int i = 0; i < traderNum; i++) {
		double vol = 10000;
		b_traders.emplace_back(Market::Trader(vol, stocks, *this));
	}
}

Market::Broker::~Broker() {}