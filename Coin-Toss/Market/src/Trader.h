#pragma once
#include "TraderStockPage.h"
#include <vector>

namespace Market {
	class Broker;
	class Trader {
	private:
		double t_currentBal;
		double t_profitLoss;
		Broker* t_broker;
		std::vector<TraderStockPage> t_stockpages;
	private:
		bool sendOrder(const Stock::Stock&, unsigned int, float);
	public:
		Trader(std::vector<Stock::Stock>&, Broker&);
		void makeDecision();
		bool orderErrorHandling();
		~Trader();
	protected:
	};
}


