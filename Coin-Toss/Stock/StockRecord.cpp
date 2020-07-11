#include "StockRecord.h"
#include <iostream>
#include <chrono>

template <size_t size>
StockRecord<size>::StockRecord(std::array<float, size>& topPrevPrice_B, std::array<float, size>& topPrevPrice_S, 
	std::array<unsigned int, size>& topPrevVol_B, std::array<unsigned int, size>& topPrevVol_S)
	:sr_topPrevPrice_B(&topPrevPrice_B), sr_topPrevPrice_S(&topPrevPrice_S),sr_topPrevVol_B(&topPrevVol_B), sr_topPrevVol_S(&topPrevVol_S) {
	candleSticks = new std::array<CandleStick, 5>{};
};