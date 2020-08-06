#include "Trader.h"
#include "Broker.h"

Market::Trader::Trader(std::vector<Stock::Stock>& stocks,const Broker& broker): t_currentBal(100000), t_profitLoss(0), t_broker(&broker){
	t_stockpages.reserve(stocks.size());
	t_updatepages.reserve(stocks.size());
	for (auto stock = stocks.begin(); stock != stocks.end(); stock++) {
		unsigned int vol = 1000;
		t_stockpages.emplace_back(TraderStockPage(*stock, t_currentBal/stocks.size(), vol, *this));
	}
}

bool Market::Trader::sendOrder(const Order& order, const TraderStockPage& stockPage) {
	t_broker->receiveOrder(order);
	t_updatepages.emplace_back(stockPage);
	return false;
}

void Market::Trader::makeDecision() {
	for (auto stockpage = t_stockpages.begin(); stockpage != t_stockpages.end(); stockpage++) {
		stockpage->executeStrat();
	}
}

void Market::Trader::orderConfirm(const Order& order) {
	if (order.o_mode == "buy") {
		t_currentBal -= (double)order.o_price * (double)order.o_volume;
	}
	if (order.o_mode == "sell") {
		t_currentBal += (double)order.o_price * (double)order.o_volume;
	}
	for (auto t_order = t_updatepages.begin(); t_order != t_updatepages.end(); t_order++) {
		if (t_order->getStock().get_stockID() == order.o_stock->get_stockID()) {
			t_order->confirmOrder(order);
			t_updatepages.erase(t_order);
			break;
		}
	}
}

bool Market::Trader::orderErrorHandling(){
	return false;
}

Market::Trader::~Trader() {}