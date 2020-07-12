#pragma once
#include "CandleStick.h"
#include <array>

namespace Stock {
	template <size_t size, size_t size_cs>
	class StockRecord {
	private:
		std::array<float, size> sr_topPrevPrice_B, sr_topPrevPrice_S;
		std::array<unsigned int, size> sr_topPrevVol_B, sr_topPrevVol_S;
		std::array<CandleStick, size_cs> sr_candleSticks;
	public:
		StockRecord(std::array<int, size_cs>&); //cs_Interval
		~StockRecord();
	protected:
	};
}


