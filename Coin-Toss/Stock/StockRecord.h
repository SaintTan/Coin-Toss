#pragma once
#include "CandleStick.h"
#include <array>

template <size_t size>
class StockRecord{
private:
	std::array<float, size>* sr_topPrevPrice;
	std::array<unsigned int, size>* sr_topPrevVol;
	std::array<CandleStick, 5>* candleSticks;
public:
	StockRecord(std::array<float, size>&, std::array<unsigned int, size>&);
protected:
};

