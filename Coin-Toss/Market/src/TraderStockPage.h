#pragma once
#include "Stock.h"
#include "Order.h"
#include <string>

namespace Market {
	class Trader;
	class TraderStockPage {
	private:
		unsigned int tsp_orderNum; //keeps track of number of orders
		double tsp_currentBal; //current balance
		double tsp_profitLoss; //total profit loss
		unsigned int tsp_volLim; //volume limit assigned to the stock
		unsigned int tsp_volume; //current held volume
		OrderQue tsp_orderques; //order que of stockpage
		Trader* tsp_trader; //trader
		const Stock::Stock* tsp_stock; //store pointer to stock 
	private:
		double calculateProfits(const Order&); //sold : calculates profit from orders - uses LIFO
	public:
		TraderStockPage(const Stock::Stock&, double, unsigned int, Trader*); //stock, totalBal, volLim, trader
		void sendOrder(const Order&); //order : inform trader of a send order
		void confirmOrder(const Order&);//order : confirms order
		void executeStrat(); //executes strategy for the stock
		const Stock::Stock& getStock(); //returns current stock
		bool errorHandling(); //: error handling * not implemented yet
		~TraderStockPage();
	protected:
	};
}


