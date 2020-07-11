#include "StockRecord.h"
#include <iostream>

template <size_t size>
StockRecord<size>::StockRecord(std::array<float, size>& topPrevPrice, std::array<unsigned int, size>& topPrevVol)
	:sr_topPrevPrice(&topPrevPrice), sr_topPrevVol(&topPrevVol) {

	candleSticks = new std::array<CandleStick, 5>{1.0f, 2.0f, 3.0f, 4.0f, 5.0f};
};