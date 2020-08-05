#include "TraderStockPage.h"

Market::TraderStockPage::TraderStockPage(const Stock::Stock& stock, double totalBal, unsigned int volLim)
	: tsp_orderNum(0), tsp_stock(&stock), tsp_currentBal(totalBal), tsp_profitLoss(0),tsp_volLim(volLim), tsp_volume(0), tsp_orderques(OrderQue(25)) {
}

double Market::TraderStockPage::calculateProfits(std::vector<Order>& buyQue, const Order& sold) {
	int vol;
	int remainingVol = sold.o_volume;
	double profits = 0;
	while (remainingVol > 0) {
		if (buyQue.back().o_volume <= remainingVol) {
			vol = buyQue.back().o_volume;
			profits += ((double)buyQue.back().o_price * (double)vol) - ((double)sold.o_price * (double)vol);
			remainingVol -= buyQue.back().o_volume;
			buyQue.pop_back();
		}
		else {
			vol = remainingVol;
			profits += ((double)buyQue.back().o_price * (double)vol) - ((double)sold.o_price * (double)vol);
			buyQue.back().o_volume -= remainingVol;
		}
	}

	return profits;

}

void Market::TraderStockPage::sendOrder() {

}


void Market::TraderStockPage::confirmOrder(const Order& order) {
	if (order.o_mode == "buy") {
		for (auto tsp_order = tsp_orderques.oq_sent_ordersB.begin(); tsp_order != tsp_orderques.oq_sent_ordersB.end(); tsp_order++) {
			if (order.o_orderID == tsp_order->o_orderID) {
				tsp_orderques.oq_sent_ordersB.erase(tsp_order);
				break;
			}
		}
		tsp_orderques.oq_confirmBuys.emplace_back(order);
		tsp_currentBal -= (double)order.o_volume * (double)order.o_price;
		tsp_volume += order.o_volume;
	}
	else if (order.o_mode == "sell") {
		for (auto tsp_order = tsp_orderques.oq_sent_ordersS.begin(); tsp_order != tsp_orderques.oq_sent_ordersS.end(); tsp_order++) {
			if (order.o_orderID == tsp_order->o_orderID) {
				tsp_orderques.oq_sent_ordersS.erase(tsp_order);
				break;
			}
		}
		tsp_profitLoss = calculateProfits(tsp_orderques.oq_confirmBuys, order);
		tsp_currentBal += (double)order.o_volume * (double)order.o_price;
		tsp_volume -= order.o_volume;
	}
	return;
}

Market::Order Market::TraderStockPage::executeStrat() {
	std::string mode("null");
	Market::Order order(*tsp_stock, tsp_orderNum++, mode, 0 ,0);
	return order;
}

bool Market::TraderStockPage::errorHandling() {
	return false;
}

std::wstring Market::TraderStockPage::getStockName() {
	return tsp_stock->get_stockID();
}

const Stock::Stock& Market::TraderStockPage::getStock() {
	return *tsp_stock;
}

Market::TraderStockPage::~TraderStockPage() {}

