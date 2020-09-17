#include "Trader.h"
#include "Broker.h"

Market::Trader::Trader(unsigned int traderID, const std::vector<Stock::Stock*>& stocks, Broker* broker): t_traderID(traderID), t_currentBal(100000), t_profitLoss(0), t_broker(broker){
	t_stockpages.reserve(stocks.size());
	unsigned int tradePage_ID = 0;
	for (auto stock : stocks) {
		unsigned int vol = 1000;
		t_stockpages.emplace_back(TraderStockPage(tradePage_ID++, *stock, t_currentBal/stocks.size(), vol, this));
	}
}

//order, stockPage : sends order to broker and keeps track of which stockpage sent the instruction
bool Market::Trader::sendOrder(const Order& order, const TraderStockPage& stockPage) {
	//telling broker of the order
	t_broker->receiveOrder(order, *this);
	return false;
}

//runs algorithm to decide on action of updated stock data
void Market::Trader::makeDecision() {
	//goes through each stockpage and executing algorithm for the stocks
	for (auto stockpage : t_stockpages) {
		stockpage.executeStrat();
	}
}

//order : confirms order
void Market::Trader::orderConfirm(const Order& order) {
	//calculating total balance
	if (order.o_mode == "buy") {
		t_currentBal -= (double)order.o_price * (double)order.o_volume;
	}
	else if (order.o_mode == "sell") {
		t_currentBal += (double)order.o_price * (double)order.o_volume;
	}
	//informs stockpages of the confirmed orders
	for (auto stockpage : t_stockpages) {
		if (stockpage.getID() == order.o_orderID) {
			stockpage.confirmOrder(order);
			break;
		}
	}
}

//: handles order * not done
bool Market::Trader::orderErrorHandling(){
	return false;
}

//overloading == operator
bool Market::Trader::operator==(const Trader&trader) const {
	return this->t_traderID == trader.t_traderID;
}

Market::Trader::~Trader() {}