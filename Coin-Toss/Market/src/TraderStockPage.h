#pragma once
#include "Stock.h"
#include <string>

namespace Market {
	struct Order {
	private:
	public:
		std::string mode;
		unsigned int volume;
		float price;
	protected:
	};
	class TraderStockPage {
	private:
		double tsp_currentBal;
		double tsp_profitLoss;
		unsigned int tsp_volLim;
		Stock::Stock* tsp_stock;
	public:
		TraderStockPage(const Stock::Stock&, double, unsigned int);
		Order executeStrat();
		std::string getStockName();
		Stock::Stock& getStock();
		bool errorHandling();
		~TraderStockPage();
	protected:
	};
}


