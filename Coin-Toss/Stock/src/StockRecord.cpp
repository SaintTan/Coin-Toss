#include "StockRecord.h"
#include <iostream>
#include <chrono>

template <size_t size>
Stock::StockRecord<size>::StockRecord(std::array<float, size>& topPrevPrice_B, std::array<float, size>& topPrevPrice_S, 
	std::array<unsigned int, size>& topPrevVol_B, std::array<unsigned int, size>& topPrevVol_S)
	:sr_topPrevPrice_B(&topPrevPrice_B), sr_topPrevPrice_S(&topPrevPrice_S),sr_topPrevVol_B(&topPrevVol_B), sr_topPrevVol_S(&topPrevVol_S) {
	float maxPrice = (*sr_topPrevPrice_S)[0];
	float minPrice = (*sr_topPrevPrice_B)[0];
	candleSticks = new std::array<CandleStick, 5>{ { {maxPrice, minPrice}, { maxPrice, minPrice }, { maxPrice, minPrice }, { maxPrice, minPrice }, { maxPrice, minPrice }}};
};

template<size_t size>
Stock::StockRecord<size>::~StockRecord() {
	delete sr_topPrevPrice_B;
	delete sr_topPrevPrice_S;
	delete sr_topPrevVol_B;
	delete sr_topPrevVol_S;

};