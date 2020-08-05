#include "TraderStockPage.h"

Market::TraderStockPage::TraderStockPage(Stock::Stock& stock, double totalBal, unsigned int volLim): tsp_stock(&stock), tsp_currentBal(totalBal), tsp_profitLoss(0),tsp_volLim(volLim) {}

Market::Order Market::TraderStockPage::executeStrat() {
	std::string mode("null");
	Market::Order order(mode, 0 ,0);
	return order;
}

bool Market::TraderStockPage::errorHandling() {
	return false;
}

std::wstring Market::TraderStockPage::getStockName() {
	return tsp_stock->get_stockID();
}

Stock::Stock& Market::TraderStockPage::getStock() {
	return *tsp_stock;
}

Market::TraderStockPage::~TraderStockPage() {}

