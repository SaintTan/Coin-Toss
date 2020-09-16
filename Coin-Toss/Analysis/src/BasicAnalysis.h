#include "StockQue.h"
#include <string>

namespace Analysis {
	namespace BasicAnalysis {
		float priceChanges(const Stock::StockQue&, const Stock::StockQue&, const std::string&);
		unsigned int volChanges(const Stock::StockQue&, const Stock::StockQue&, const std::string&);
	}
}