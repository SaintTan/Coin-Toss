#include "BasicStrat.h"
#include <iostream>

bool TradeStrat::BasicStrat::checkPriceChanges(const Stock::Stock& stock) {
	/*const Stock::StockQue* current = stock.getStockQue();
	const Stock::StockQue* previous = stock.getStockRecord()->getStockQue();
	std::cout << previous->mq_topPrice_B.empty() << std::endl;
	if (previous->mq_topPrice_B.empty()) {
		return false;
	}
	float sell_pc = Analysis::BasicAnalysis::priceChanges(*current, *previous, "sell");
	float buy_pc = Analysis::BasicAnalysis::priceChanges(*current, *previous, "buy");
	std::cout << "buysell" << std::endl;
	std::cout << sell_pc << std::endl;
	std::cout << buy_pc << std::endl;
	if (sell_pc > 0 || buy_pc > 0) {
		return true;
	}*/
	return false;
}