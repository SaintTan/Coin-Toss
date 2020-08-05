#pragma once
#include "TraderStockPage.h"
#include <vector>

namespace Market {
	class Broker;
	class Trader {
	private:
		double t_currentBal;
		double t_profitLoss;
		const Broker* t_broker;
		std::vector<Order> t_sentOrders;
		std::vector<Order> t_activeOrders;
		std::vector<TraderStockPage> t_stockpages;
	private:
		bool sendOrder(const Stock::Stock&, unsigned int, float);
	public:
		Trader(std::vector<Stock::Stock>&, const Broker&);
		void makeDecision();
		void orderConfirm(const Order& order);
		bool orderErrorHandling();
		~Trader();
	protected:
	};
}


