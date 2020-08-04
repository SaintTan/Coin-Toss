#include "Broker.h"

Market::Broker::Broker(const std::string& brokerID, unsigned int traderNum, const std::vector<Stock::Stock>& stocks): b_brokerID(brokerID) {
	b_traders.reserve(traderNum);
	for (auto trader = b_traders.begin; trader != b_trader.end; trader++) {
		b_traders.emplace_back(Market::Trader(stocks));
	}
}