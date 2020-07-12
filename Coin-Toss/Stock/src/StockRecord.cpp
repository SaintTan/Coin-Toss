#include "StockRecord.h"
#include <iostream>
#include <chrono>

template <size_t size, size_t size_cs>
Stock::StockRecord<size,size_cs>::StockRecord(std::array<int, size_cs>& csInterval)
	:sr_topPrevPrice_B(std::array<float, size>{}), sr_topPrevPrice_S(std::array<float, size>{}), sr_topPrevVol_B(std::array<unsigned int, size>{}),
	sr_topPrevVol_S(std::array<unsigned int, size>{}), sr_candleSticks(std::array<CandleStick, size_cs>{}) {
	for (unsigned int i = 0; i < csInterval.size(); i++) {
		sr_candleSticks[i].setInterval(csInterval[i]);
	}
};

template <size_t size, size_t size_cs>
void Stock::StockRecord<size, size_cs>::updateStockRecord(std::array<float, size>& topCurPrice_B, std::array<float, size>& topCurPrice_S, std::array<unsigned int, size>& topCurVol_B,
	std::array<unsigned int, size>& topCurVol_S) {
	sr_topPrevPrice_B = topCurPrice_B;
	sr_topPrevPrice_S = topCurPrice_S;
	sr_topPrevVol_B = topCurVol_B;
	sr_topPrevVol_S = topCurVol_S;
	for (unsigned int i = 0; i < sr_candleSticks.size(); i++) {
		sr_candleSticks[i].updateCandleStick(sr_topPrevPrice_S[0], sr_topPrevPrice_B[0]);
	}
}

template<size_t size, size_t size_cs>
Stock::StockRecord<size,size_cs>::~StockRecord() {};