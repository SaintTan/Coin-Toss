#include "Trader.h"

Market::Trader::Trader(std::vector<Stock::Stock>& stocks,const Broker& broker): t_currentBal(100000), t_profitLoss(0), t_broker(&broker){
	t_stockpages.reserve(stocks.size());
	for (auto stock = stocks.begin(); stock != stocks.end(); stock++) {
		unsigned int vol = 1000;
		t_stockpages.emplace_back(TraderStockPage(*stock, t_currentBal/stocks.size(), vol));
	}
}

bool Market::Trader::sendOrder(const Stock::Stock& stock, unsigned int volume, float price) {
	return false;
}

void Market::Trader::makeDecision() {
	Order* order;
	for (auto stockpage = t_stockpages.begin(); stockpage != t_stockpages.end(); stockpage++) {
		order = &stockpage->executeStrat();
		if (order->o_mode != "null") {
			sendOrder( stockpage->getStock(), order->o_volume, order->o_price);
		}
	}
}

void Market::Trader::orderConfirm(const Order& order) {
	if (order.o_mode == "buy") {
		t_currentBal -= (double)order.o_price * (double)order.o_volume;
	}
	if (order.o_mode == "sell") {
		t_currentBal += (double)order.o_price * (double)order.o_volume;
	}
}

bool Market::Trader::orderErrorHandling(){
	return false;
}

Market::Trader::~Trader() {}