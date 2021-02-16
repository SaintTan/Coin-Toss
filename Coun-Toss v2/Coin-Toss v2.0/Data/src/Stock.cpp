#include "Stock.h"

Data::Stock::Stock(const std::string& stockID, const StockInfo& stockinfo) :stockID(stockID), curInfo(&stockinfo), prevInfo(nullptr) {};