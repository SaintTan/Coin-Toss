#pragma once
#include "Stock.h"
#include "Order.h"
#include <vector>
#include <string>

namespace Market {
	
	class TraderStockPage {
	private:
		unsigned int tsp_orderNum;
		double tsp_currentBal;
		double tsp_profitLoss;
		unsigned int tsp_volLim;
		unsigned int tsp_volume;
		std::vector<Order> tsp_sentOrder;
		std::vector<Order> tsp_activeOrder;
		const Stock::Stock* tsp_stock;
	public:
		TraderStockPage(const Stock::Stock&, double, unsigned int);
		void sendOrder();
		void confirmOrder(const Order&);
		Order executeStrat();
		std::wstring getStockName();
		const Stock::Stock& getStock();
		bool errorHandling();
		~TraderStockPage();
	protected:
	};
}


