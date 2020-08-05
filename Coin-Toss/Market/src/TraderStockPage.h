#pragma once
#include "Stock.h"
#include "Order.h"
#include <string>

namespace Market {
	class Trader;
	class TraderStockPage {
	private:
		unsigned int tsp_orderNum;
		double tsp_currentBal;
		double tsp_profitLoss;
		unsigned int tsp_volLim;
		unsigned int tsp_volume;
		OrderQue tsp_orderques;
		const Trader* tsp_trader;
		const Stock::Stock* tsp_stock;
	private:
		double calculateProfits(std::vector<Order>&, const Order&);
	public:
		TraderStockPage(const Stock::Stock&, double, unsigned int, const Trader&);
		void sendOrder(unsigned int, float);
		void confirmOrder(const Order&);
		void executeStrat();
		std::wstring getStockName();
		const Stock::Stock& getStock();
		bool errorHandling();
		~TraderStockPage();
	protected:
	};
}


