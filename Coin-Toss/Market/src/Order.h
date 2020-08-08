#pragma once
#include "Stock.h"
#include <vector>
#include <string>

namespace Market {
	struct Order {
	private:
	public:
		const Stock::Stock* o_stock; //pointer to stock
		unsigned int o_orderID; //orderID
		unsigned int o_sender;
		std::string o_mode; //mode of transaction
		unsigned int o_volume; //volume
		float o_price; //price
		
	public:
		Order(const Stock::Stock& stock, unsigned int order_id, unsigned int sender, const std::string& mode, unsigned int volume, float price):
			o_stock(&stock), o_orderID(order_id), o_sender(sender), o_mode(mode), o_volume(volume), o_price(price) {}
	protected:
	};

	struct OrderQue {
	private:
	public:
		std::vector<Order> oq_sent_ordersB; //stores sent buy orders
		std::vector<Order> oq_sent_ordersS; //stores sent sell orders
		std::vector<Order> oq_confirmBuys; //stores orders of confirmed bought

		OrderQue(unsigned int num) {
			oq_sent_ordersB.reserve(num);
			oq_sent_ordersS.reserve(num);
			oq_confirmBuys.reserve(num);
		}
	public:
	};
}
