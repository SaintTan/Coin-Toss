#include "BasicStrat.h"
#include <iostream>

int TradeStrat::BasicStrat::checkPriceChanges(const Stock::Stock& stock) {
	const Stock::StockQue* current = stock.getStockQue();
	const Stock::StockQue* previous = stock.getStockRecord()->getStockQue();
	float sell_pc = Analysis::BasicAnalysis::priceChanges(*current, *previous, "sell");
	float buy_pc = Analysis::BasicAnalysis::priceChanges(*current, *previous, "buy");
	if (sell_pc > 0 && buy_pc > 0) {
		return 1;
	}
	else if (sell_pc < 0 && buy_pc < 0) {
		return -1;
	}
	return 0;
}