#pragma once
#include "Stock.h"
#include <vector>
#include <string>

namespace Market {
	struct Order {
	private:
	public:
		const Stock::Stock* o_stock; //pointer to stock
		uint32_t o_orderID; //orderID
		uint32_t o_sender;
		std::string o_mode; //mode of transaction
		uint32_t o_volume; //volume
		float o_price; //price
		
	public:
		Order(const Stock::Stock& stock, uint32_t order_id, uint32_t sender, const std::string& mode, uint32_t volume, float price):
			o_stock(&stock), o_orderID(order_id), o_sender(sender), o_mode(mode), o_volume(volume), o_price(price) {}
	protected:
	};

	struct OrderQue {
	private:
	public:
		std::vector<Order> oq_sent_ordersB; //stores sent buy orders
		std::vector<Order> oq_sent_ordersS; //stores sent sell orders
		std::vector<Order> oq_confirmBuys; //stores orders of confirmed bought

		OrderQue(uint32_t num) {
			oq_sent_ordersB.reserve(num);
			oq_sent_ordersS.reserve(num);
			oq_confirmBuys.reserve(num);
		}
	public:
	};
}
