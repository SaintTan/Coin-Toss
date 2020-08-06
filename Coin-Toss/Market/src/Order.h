#pragma once
#include "Stock.h"
#include <vector>
#include <string>

namespace Market {
	struct Order {
	private:
	public:
		const Stock::Stock* o_stock;
		unsigned int o_orderID;
		std::string o_mode;
		unsigned int o_volume;
		float o_price;
		
	public:
		Order(const Stock::Stock& stock, unsigned int order_id, const std::string& mode, unsigned int volume, float price):
			o_stock(&stock), o_orderID(order_id),o_mode(mode), o_volume(volume), o_price(price) {}
	protected:
	};

	struct OrderQue {
	private:
	public:
		std::vector<Order> oq_sent_ordersB;
		std::vector<Order> oq_sent_ordersS;
		std::vector<Order> oq_confirmBuys;

		OrderQue(unsigned int num) {
			oq_sent_ordersB.reserve(num);
			oq_sent_ordersS.reserve(num);
			oq_confirmBuys.reserve(num);
		}
	public:
	};
}
