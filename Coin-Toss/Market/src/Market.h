#pragma once
#include "Stock.h"
#include <string>
#include <vector>

namespace Market {
	class Market {
	private:
		std::string marketID;
		std::vector<Stock::Stock> stocks;

	public:
		Market();
		void updateStock();
		~Market();
	protected:
	};
}

