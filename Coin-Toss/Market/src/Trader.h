#pragma once
#include "TraderStockPage.h"
#include <vector>

namespace Market {
	class Broker;
	class Trader {
	private:
		uint32_t t_traderID; //trader ID
		double t_currentBal; //current balance 
		double t_profitLoss; //profit or loss
		Broker* t_broker; //pointer to broker responsible for the trader
		std::vector<TraderStockPage*> t_stockpages; //stock pages
	public:
		Trader(uint32_t, const std::vector<Stock::Stock*>&, Broker*); //traderID, stocks, broker
		bool sendOrder(const Order&, const TraderStockPage&); //order, stockPage : sends order to broker and keeps track of which stockpage sent the instruction
		void makeDecision(); //runs algorithm to decide on action of updated stock data
		void orderConfirm(const Order&); //order : confirms order
		bool orderErrorHandling(); //: handles order * not done
		bool operator==(const Trader&) const; //overloading == operator
		~Trader();
	protected:
	};
}


