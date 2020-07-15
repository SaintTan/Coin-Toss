#include "StockRecord.h"

template <size_t size>
Stock::StockRecord<size>::StockRecord()
	:sr_topPrevPrice_B(std::array<float, size>{}), sr_topPrevPrice_S(std::array<float, size>{}), sr_topPrevVol_B(std::array<unsigned int, size>{}),
	sr_topPrevVol_S(std::array<unsigned int, size>{}) {};

template <size_t size>
void Stock::StockRecord<size>::updateStockRecord(std::array<float, size>& topCurPrice_B, std::array<float, size>& topCurPrice_S, std::array<unsigned int, size>& topCurVol_B,
	std::array<unsigned int, size>& topCurVol_S) {
	sr_topPrevPrice_B = topCurPrice_B;
	sr_topPrevPrice_S = topCurPrice_S;
	sr_topPrevVol_B = topCurVol_B;
	sr_topPrevVol_S = topCurVol_S;
	
}

template<size_t size>
Stock::StockRecord<size>::~StockRecord() {};