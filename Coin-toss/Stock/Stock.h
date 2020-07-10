#pragma once
#include <string>
#include <array>

template<size_t size>
class Stock{
private:
	std::string stockID;
	std::array<float, size>* topCurPrice;
	std::array<int, size>* topCurVol;
	int totalCurVol;
public:
	Stock(const std::string& s_stockID, std::array<float,size>* s_prices,
		std::array<int,size>* s_volume, int s_totalCurVol);
protected:
};

