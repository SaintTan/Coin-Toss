#include "TraderStockPage.h"

Market::TraderStockPage::TraderStockPage(const Stock::Stock& stock, double totalBal, unsigned int volLim)
	: tsp_orderNum(0), tsp_stock(&stock), tsp_currentBal(totalBal), tsp_profitLoss(0),tsp_volLim(volLim), tsp_volume(0) {
	tsp_sentOrder.reserve(50);
	tsp_activeOrder.reserve(50);
}

void Market::TraderStockPage::sendOrder() {

}


void Market::TraderStockPage::confirmOrder(const Order& order) {
	for (auto tsp_order = tsp_activeOrder.begin(); tsp_order != tsp_activeOrder.end(); tsp_order++) {
		if (order.o_orderID == tsp_order->o_orderID) {
			tsp_activeOrder.erase(tsp_order);
			break;
		}
	}

	if (order.o_mode == "buy") {
		tsp_currentBal -= (double)order.o_volume * (double)order.o_price;
		tsp_volume += order.o_volume;
	}
	else if (order.o_mode == "sell") {
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

