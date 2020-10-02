#pragma once
#include "Stock.h"
#include "Order.h"
#include <string>
#include "BasicStrat.h"
#include "VolPercentage.h"
#include "GetBestPrice.h"

namespace Market {
	class Trader;
	class TraderStockPage {
	private:
		uint32_t tsp_ID;
		uint32_t tsp_orderNum; //keeps track of number of orders
		double tsp_currentBal; //current balance
		double tsp_profitLoss; //total profit loss
		uint32_t tsp_volLim; //volume limit assigned to the stock
		uint32_t tsp_volume; //current held volume
		OrderQue* tsp_orderques; //order que of stockpage
		Trader* tsp_trader; //trader
		const Stock::Stock* tsp_stock; //store pointer to stock 
	private:
		double calculateProfits(const Order&); //sold : calculates profit from orders - uses LIFO
	public:
		TraderStockPage(uint32_t, const Stock::Stock&, double, uint32_t, Trader*); //id, stock, totalBal, volLim, trader
		void sendOrder(const Order&); //order : inform trader of a send order
		void confirmOrder(const Order&);//order : confirms order
		void executeStrat(); //executes strategy for the stock
		uint32_t getID() const; // returns traderstockpage ID
		bool errorHandling(); //: error handling * not implemented yet
		~TraderStockPage();
	protected:
	};
}


