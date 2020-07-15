#pragma once
#include "CandleStick.h"
#include <array>

namespace Stock {
	template <size_t size>
	class StockRecord {
	private:
		std::array<float, size> sr_topPrevPrice_B, sr_topPrevPrice_S;
		std::array<unsigned int, size> sr_topPrevVol_B, sr_topPrevVol_S;
		
	public:
		StockRecord(); //cs_Interval
		void updateStockRecord(std::array<float, size>&, std::array<float, size>&, std::array<unsigned int, size>&, std::array<unsigned int, size>&);
		~StockRecord();
	protected:
	};
}


