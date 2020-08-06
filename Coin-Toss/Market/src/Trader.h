#pragma once
#include "TraderStockPage.h"
#include <vector>

namespace Market {
	class Broker;
	class Trader {
	private:
		unsigned int t_traderID;
		double t_currentBal;
		double t_profitLoss;
		Broker* t_broker;
		std::vector<TraderStockPage> t_updatepages;
		std::vector<TraderStockPage*> t_stockpages;
	public:
		Trader(unsigned int, std::vector<Stock::Stock>&, Broker*);
		bool sendOrder(const Order&, const TraderStockPage&);
		void makeDecision();
		void orderConfirm(const Order& order);
		bool orderErrorHandling();
		unsigned int getID() const;
		bool operator==(const Trader&) const;
		~Trader();
	protected:
	};
}


