#include "BasicStrat.h"
#include <iostream>

bool TradeStrat::BasicStrat::checkPriceChanges(const Stock::Stock& stock) {
	const Stock::StockQue* current = stock.getStockQue();
	const Stock::StockQue* previous = stock.getStockRecord()->getStockQue();
	float sell_pc = Analysis::BasicAnalysis::priceChanges(*current, *previous, "sell");
	float buy_pc = Analysis::BasicAnalysis::priceChanges(*current, *previous, "buy");
	if (sell_pc > 0 || buy_pc > 0) {
		return true;
	}
	return false;
}