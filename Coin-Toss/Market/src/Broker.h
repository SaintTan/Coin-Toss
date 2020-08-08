#pragma once
#include "Trader.h"
#include "Stock.h"
#include "Order.h"
#include <vector>
#include <string>

namespace Market {
	class Broker {
	private:
		std::string b_brokerID; //ID for broker
		std::vector<Trader*> b_traders; //stores pointers to traders
	public:
		Broker(const std::string&, unsigned int, std::vector<Stock::Stock>&); //brokerID, traderNum, stocks
		void receiveOrder(const Order&, const Trader&); //order, trader : receives order and identify which trader made the order
		void confirmOrder(const Order&, const Trader&); //order, trader : confirms order and notify trader
		void receiveUpdate(); //receives dataupdate and informs traders
		~Broker();
	protected:
	};
}


