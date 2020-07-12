#include "StockRecord.h"
#include <iostream>
#include <chrono>

template <size_t size, size_t size_cs>
Stock::StockRecord<size,size_cs>::StockRecord(std::array<int, size_cs>& csInterval)
	:sr_topPrevPrice_B(std::array<float, size>{}), sr_topPrevPrice_S(std::array<float, size>{}),
	sr_topPrevVol_B(std::array<unsigned int, size>{}), sr_topPrevVol_S(std::array<unsigned int, size>{}), sr_candleSticks(std::array<CandleStick, size_cs>{}) {
	for (unsigned int i = 0; i < csInterval.size(); i++) {
		sr_candleSticks[i].setInterval(csInterval[i]);
	}
};

template<size_t size, size_t size_cs>
Stock::StockRecord<size,size_cs>::~StockRecord() {};