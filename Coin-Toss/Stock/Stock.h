#pragma once
#include "StockRecord.h"
#include <string>
#include <array>

template <size_t size>
class Stock{
private:
	std::string s_stockID;
	std::array<float, size>* s_topCurPrice;
	std::array<unsigned int, size>* s_topCurVol;
	StockRecord<size>* stockRecord;
	unsigned int s_totalVol;
public:
	Stock(const std::string&, std::array<float, size>&, std::array<unsigned int, size>&, unsigned int);
protected:
};

#include "StockRecord.cpp"