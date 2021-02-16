#pragma once
#include "StockInfo.h"
#include <string>

namespace Data {
	class Stock {
	private:
		const std::string stockID;
		const StockInfo* prevInfo;
		const StockInfo* curInfo;
	public:
		Stock(const std::string&, const StockInfo&);
	};
}


