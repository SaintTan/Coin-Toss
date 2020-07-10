#include "Stock.h"
#include <iostream>

template <size_t size>
Stock<size>::Stock(const std::string& stockID, std::array<float, size>& topCurPrice, std::array<unsigned, size>& topCurVol, unsigned int totalVol)
	:s_stockID(stockID), s_topCurPrice(&topCurPrice), s_topCurVol(&topCurVol), s_totalVol(totalVol) {
	std::array<float, size>* topPrevPrice = new std::array<float, size>({});
	std::array<unsigned int, size>* topPrevVol = new std::array<unsigned int, size>({});
	stockRecord = new StockRecord<size>(*topPrevPrice, *topPrevVol);
};

int main() {
	const std::string stockID("001");
	std::array<float, 3> topCurPrice = { 1,2,3 };
	std::array<unsigned int, 3> topCurVol = { 1,2,3 };
	unsigned int totalvol = 1 + 2 + 3;
	Stock<3> stock(stockID,topCurPrice, topCurVol, totalvol);
}