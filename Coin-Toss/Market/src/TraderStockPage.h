#pragma once
#include "Stock.h"
#include "Order.h"
#include <string>

namespace Market {
	
	class TraderStockPage {
	private:
		double tsp_currentBal;
		double tsp_profitLoss;
		unsigned int tsp_volLim;
		Stock::Stock* tsp_stock;
	public:
		TraderStockPage(Stock::Stock&, double, unsigned int);
		Order executeStrat();
		std::wstring getStockName();
		Stock::Stock& getStock();
		bool errorHandling();
		~TraderStockPage();
	protected:
	};
}


