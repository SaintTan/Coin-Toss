#pragma once
#include "TraderStockPage.h"
#include <vector>

namespace Market {
	class Trader {
	private:
		double t_currentBal;
		double t_profitLoss;
		std::vector<TraderStockPage> t_astockpages;
	private:
		bool sendBuyOrder(const Stock::Stock, unsigned int, float);
		bool sendSellOrder(const Stock::Stock, unsigned int, float);
	public:
		Trader(double, const std::vector<Stock::Stock>&);
		void makeDecision();
		bool orderErrorHandling();
		~Trader();
	protected:
	};
}


