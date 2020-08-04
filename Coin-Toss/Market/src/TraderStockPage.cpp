#include "TraderStockPage.h"

Market::TraderStockPage::TraderStockPage(const Stock::Stock& stock, double totalBal, unsigned int volLim): tsp_stock(&stock), tsp_currentBal(totalBal), tsp_profitLoss(0),tsp_volLim(volLim) {}

Market::Order Market::TraderStockPage::executeStrat() {
}

bool Market::TraderStockPage::errorHandling() {
	return false;
}

std::string Market::TraderStockPage::getStockName() {
	return tsp_stock->get_stockID();
}

Stock::Stock& Market::TraderStockPage::getStock() {
	return *tsp_stock;
}

Market::TraderStockPage::~TraderStockPage() {}

