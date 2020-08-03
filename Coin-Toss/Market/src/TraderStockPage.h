#pragma once
#include "Stock.h"

namespace Market {
	class TraderStockPage {
	private:
		double tsp_currentBal;
		double tsp_profitLoss;
		unsigned int tsp_volLim;
		Stock::Stock* tsp_stock;
	public:
		TraderStockPage(const Stock::Stock&, double, unsigned int);
		int executeStrat();
		bool errorHandling();
		~TraderStockPage();
	protected:
	};
}


