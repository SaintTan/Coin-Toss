#pragma once
#include "Trader.h"
#include "Stock.h"
#include <vector>
#include <string>

namespace Market {
	class Broker {
	private:
		std::string b_brokerID;
		std::vector<Trader> b_traders;
	public:
		Broker(const std::string&, unsigned int, std::vector<Stock::Stock>&);
		void receiveOrder(const Order&) const;
		~Broker();
	protected:
	};
}


