#include "TraderStockPage.h"
#include "Trader.h"
#include <iostream>

Market::TraderStockPage::TraderStockPage(unsigned int ID, Stock::Stock& stock, double totalBal, unsigned int volLim, Trader* trader)
	: tsp_ID(ID),tsp_orderNum(0), tsp_stock(&stock), tsp_currentBal(totalBal), tsp_profitLoss(0),tsp_volLim(volLim), tsp_volume(0), tsp_trader(trader), tsp_orderques(OrderQue(25)) {
}

//calculates profit from orders - uses LIFO
double Market::TraderStockPage::calculateProfits(const Order& sold) {
	int vol;
	int remainingVol = sold.o_volume;
	double profits = 0;
	while (remainingVol > 0) {
		//compares volume differences
		if ((int)tsp_orderques.oq_confirmBuys.back().o_volume <= remainingVol) {
			vol = tsp_orderques.oq_confirmBuys.back().o_volume;
			//calculates profits
			profits += ((double)tsp_orderques.oq_confirmBuys.back().o_price * (double)vol) - ((double)sold.o_price * (double)vol);
			//calculates remaining volume
			remainingVol -= tsp_orderques.oq_confirmBuys.back().o_volume;
			//deletes confirmed buys
			tsp_orderques.oq_confirmBuys.pop_back();
		}
		else {
			vol = remainingVol;
			//calculates profit
			profits += ((double)tsp_orderques.oq_confirmBuys.back().o_price * (double)vol) - ((double)sold.o_price * (double)vol);
			//updates stock's volume
			tsp_orderques.oq_confirmBuys.back().o_volume -= remainingVol;
			remainingVol = 0;
		}
	}

	return profits;

}

//inform trader of a send order
void Market::TraderStockPage::sendOrder(const Order& order) {
	//adding sent orders to respective fields
	if (order.o_mode == "buy") {
		tsp_orderques.oq_sent_ordersB.emplace_back(order);
	}
	else if (order.o_mode == "sell") {
		tsp_orderques.oq_sent_ordersS.emplace_back(order);
	}
	
	//informs trader
	tsp_trader->sendOrder(order, *this);
	
	return;
}

//confirms order
void Market::TraderStockPage::confirmOrder(const Order& order) {
	if (order.o_mode == "buy") {
		//deletes sent orders of buy
		for (auto tsp_order = tsp_orderques.oq_sent_ordersB.begin(); tsp_order != tsp_orderques.oq_sent_ordersB.end(); tsp_order++) {
			if (order.o_orderID == tsp_order->o_orderID) {
				tsp_orderques.oq_sent_ordersB.erase(tsp_order);
				break;
			}
		}
		//adding it into confirmed secured volume
		tsp_orderques.oq_confirmBuys.emplace_back(order);
		//updates current balance and volumes
		tsp_currentBal -= (double)order.o_volume * (double)order.o_price;
		tsp_volume += order.o_volume;
	}
	else if (order.o_mode == "sell") {
		//deletes sent orders of sell
		for (auto tsp_order = tsp_orderques.oq_sent_ordersS.begin(); tsp_order != tsp_orderques.oq_sent_ordersS.end(); tsp_order++) {
			if (order.o_orderID == tsp_order->o_orderID) {
				tsp_orderques.oq_sent_ordersS.erase(tsp_order);
				break;
			}
		}
		//calculates profits 
		tsp_profitLoss += calculateProfits(order);
		//updates current balance and volume
		tsp_currentBal += (double)order.o_volume * (double)order.o_price;
		tsp_volume -= order.o_volume;
	}
	return;
}

//executes strategy for the stock
void Market::TraderStockPage::executeStrat(){
	std::string mode("buy");
	TradeStrat::BasicStrat basicStrat;
	float priceC = basicStrat.checkPriceChanges(*tsp_stock);
	if (basicStrat.checkPriceChanges(*tsp_stock)) {
		mode = "buy";
	}
	else {
		mode = "sell";
	}
	//std::cout << mode << std::endl;
	//std::cout << priceC << std::endl;
	Market::Order order(*tsp_stock, tsp_ID, tsp_orderNum++, mode, 0 ,0);
	sendOrder(order);
	return;
}

//returns current stock
unsigned int Market::TraderStockPage::getID() const {
	return tsp_ID;
}

//: error handling * not implemented yet
bool Market::TraderStockPage::errorHandling() {
	return false;
}



Market::TraderStockPage::~TraderStockPage() {}

