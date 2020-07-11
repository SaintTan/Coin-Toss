#pragma once
#include "CandleStick.h"
#include <array>

template <size_t size>
class StockRecord{
private:
	std::array<float, size>* sr_topPrevPrice_B, *sr_topPrevPrice_S;
	std::array<unsigned int, size>* sr_topPrevVol_B, *sr_topPrevVol_S;
	std::array<CandleStick, 5>* candleSticks;
public:
	StockRecord(std::array<float, size>&, std::array<float, size>&, std::array<unsigned int, size>&, std::array<unsigned int, size>&); //topPrevPrice_B topPrevPrice_S topPrevVol_B topPrevVol_S
	~StockRecord();
protected:
};

