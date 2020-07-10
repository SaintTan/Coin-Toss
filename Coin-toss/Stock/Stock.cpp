#include "Stock.h"
#include <iostream>

template <size_t size>
Stock<size>::Stock(const std::string& s_stockID, std::array<float, size>* s_prices,
	std::array<int, size>* s_volume, int s_totalCurVol)
	:stockID(s_stockID), topCurPrice(s_prices), topCurVol(s_volume), totalCurVol(s_totalCurVol) {}

int main() {
	std::cout << "Initializing Stocks" << std::endl;
	std::array<float, 3> price = {0.1f,0.2f,0.3f};
	std::array<int, 3> volume = { 0,1,2 };
	Stock<3> stock(std::string("001"), &price, &volume, 0);
	std::cin.get();
}