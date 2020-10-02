#pragma once
#include "StockQue.h"
#include <string>

namespace Analysis {
	namespace BasicAnalysis {
		float priceChanges(const Stock::StockQue&, const Stock::StockQue&, const std::string&);
		uint32_t volChanges(const Stock::StockQue&, const Stock::StockQue&, const std::string&);
	}
}