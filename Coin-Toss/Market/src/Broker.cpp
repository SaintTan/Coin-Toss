#include "Broker.h"

Market::Broker::Broker(const std::string& brokerID, unsigned int traderNum, std::vector<Stock::Stock>& stocks): b_brokerID(brokerID) {
	b_updateTraders.reserve(traderNum);
	b_traders.reserve(traderNum);
	for (unsigned int i = 0; i < traderNum; i++) {
		b_traders.emplace_back(Market::Trader(i, stocks, *this));
	}
}

void Market::Broker::receiveOrder(const Order& order, const Market::Trader& trader){
	b_updateTraders.emplace_back(trader);
	confirmOrder(order, trader);
}

void Market::Broker::confirmOrder(const Order& order, const Market::Trader& trader) {
	for (auto b_trader = b_updateTraders.begin(); b_trader != b_updateTraders.end(); b_trader++) {
		if (*b_trader == trader) {
			b_trader->orderConfirm(order);
			b_updateTraders.erase(b_trader);
			break;
		}
	}
	return;
}

void Market::Broker::receiveUpdate() {
	for (auto trader = b_traders.begin(); trader != b_traders.end(); trader++) {
		trader->makeDecision();
	}
}

Market::Broker::~Broker() {}