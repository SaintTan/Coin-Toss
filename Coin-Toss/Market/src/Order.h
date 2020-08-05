#pragma once
#include <string>

namespace Market {
	struct Order {
	private:
	public:
		unsigned int o_orderID;
		std::string o_mode;
		unsigned int o_volume;
		float o_price;
	public:
		Order(const std::string& mode, unsigned int volume, float price):o_orderID(0),o_mode(mode), o_volume(volume), o_price(price) {}
	protected:
	};
}
