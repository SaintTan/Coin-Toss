#include "Trader.h"

Market::Trader::Trader(double totalBal, const std::vector<Stock::Stock>& stocks, Broker& broker): t_currentBal(totalBal), t_profitLoss(0), t_broker(&broker){
	t_stockpages.reserve(stocks.size());
	for (auto stock = stocks.begin(); stock != stocks.end(); stock++) {
		t_stockpages.emplace_back(*stock);
	}
}

bool Market::Trader::sendOrder(const Stock::Stock& stock, unsigned int volume, float price) {
	
}

void Market::Trader::makeDecision() {
	Order order;
	for (auto stockpage = t_stockpages.begin(); stockpage != t_stockpages.end(); stockpage++) {
		order = stockpage->executeStrat();
		if (order.mode != "null") {
			sendOrder( stockpage->getStock(), order.volume, order.price);
		}
	}
}

bool Market::Trader::orderErrorHandling(){}

Market::Trader::~Trader() {}