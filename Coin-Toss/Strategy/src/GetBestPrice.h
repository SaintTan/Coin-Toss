#pragma once
#include "StockQue.h"
#include <string>

namespace PriceStrat {
	class GetBestPrice{
	private:
	public:
		GetBestPrice();
		float getPrice(const Stock::StockQue&, const std::string&);
	protected:
	};
}


