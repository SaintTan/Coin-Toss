#include "TraderStockPage.h"

Market::TraderStockPage::TraderStockPage(const Stock::Stock& stock, double totalBal, unsigned int volLim): tsp_stock(&stock), tsp_currentBal(totalBal), tsp_profitLoss(0),tsp_volLim(volLim) {}

int Market::TraderStockPage::executeStrat() {
	return 0;
}

bool Market::TraderStockPage::errorHandling() {
	return false;
}

Market::TraderStockPage::~TraderStockPage() {}

