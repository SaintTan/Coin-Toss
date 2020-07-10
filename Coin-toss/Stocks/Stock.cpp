#include "Stock.h"
#include "StockRecord.h"
#include <iostream>

template <size_t size>

class Stock {
public:
	std::string stockID;
	std::array<float, size>* topCurPrice;
	std::array<int, size>* topCurVol;
	StockRecord stockRecord();
public:
	Stock(const std::string& stockID, std::array<float, size>& topCurPrice, std::array<int, size>& topCurVol)
		:stockID(stockID), topCurPrice(topCurPrice), topCurVol(topCurVol) {
		std::cout << "create Stock" << std::endl;
	}
	std::ostream& operator<<(std::ostream& stream, Stock stock) const {
		stream << "stockID :" << stock.stockID << "\n" << "topCurPrice" << stock.topCurPrice << "\n";
		return stream;
	}
protected:

};

int main() {
	std::cout << "starting stock" << std::endl;
	std::array<float, 5> topCurPrice = { 0.1f,0.2f,0.3f };
	std::array<int, 5> topCurVol = { 1,2,3 };
	Stock<5> stock(std::string("001"), topCurPrice, topCurVol);
}