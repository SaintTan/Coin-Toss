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
		std::vector<TraderStockPage> t_updatepages;
		std::vector<TraderStockPage> t_stockpages;
	public:
		Trader(std::vector<Stock::Stock>&, const Broker&);
		bool sendOrder(const Order&, const TraderStockPage&);
		void makeDecision();
		void orderConfirm(const Order& order);
		bool orderErrorHandling();
		~Trader();
	protected:
	};
}


