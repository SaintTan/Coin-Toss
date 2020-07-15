#pragma once
#include "StockRecord.h"
#include <string>
#include <array>

namespace Stock {
	template <size_t size, size_t size_cs>
	class Stock {
	private:
		std::string s_stockID;
		std::array<float, size>* s_topCurPrice_B,* s_topCurPrice_S;
		std::array<unsigned int, size>* s_topCurVol_B,* s_topCurVol_S;
		StockRecord<size> s_stockRecord;
		std::array<CandleStick, size_cs> s_candleSticks;
		unsigned int s_totalVol;
	public:
		Stock(const std::string&, std::array<float, size>&, std::array<float, size>&, std::array<unsigned int, size>&, std::array<unsigned int, size>&,
			std::array<unsigned int, size_cs>&, unsigned int); //stockID, s_topCurPrice_B, s_topCurPrice_S, s_topCurVol_B, s_topCurVol_S, cs_interval, total_vol
		void updateStock(int);
		~Stock();
	protected:
	};
}


#include "StockRecord.cpp"