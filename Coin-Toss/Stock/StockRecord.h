#pragma once

#include<array>

template <size_t size>
class StockRecord{
private:
	std::array<float, size>* sr_topPrevPrice;
	std::array<unsigned int, size>* sr_topPrevVol;
public:
	StockRecord(std::array<float, size>&, std::array<unsigned int, size>&);
protected:
};

