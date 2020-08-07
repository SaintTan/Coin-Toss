#include "Broker.h"

Market::Broker::Broker(const std::string& brokerID, unsigned int traderNum, std::vector<Stock::Stock>& stocks): b_brokerID(brokerID){
	b_traders.reserve(traderNum);
	for (unsigned int i = 0; i < traderNum; i++) {
		b_traders.emplace_back(new Market::Trader(i, stocks, this));
	}
}

//order, trader : receives order and identify which trader made the order
void Market::Broker::receiveOrder(const Order& order, const Market::Trader& trader){
	confirmOrder(order, trader);
}

//order, trader : confirms order and notify trader
void Market::Broker::confirmOrder(const Order& order, const Market::Trader& trader) {
	//looks for trader and informs them
	for (auto b_trader = b_traders.begin(); b_trader != b_traders.end(); b_trader++) {
		if (*(*b_trader) == trader) {
			(*b_trader)->orderConfirm(order);
		}
	}
	return;
}

//receives dataupdate and informs traders
void Market::Broker::receiveUpdate() {
	//updates every trader
	for (auto trader = b_traders.begin(); trader != b_traders.end(); trader++) {
		(*trader)->makeDecision();
	}
}

Market::Broker::~Broker() {
	b_traders.clear();
}