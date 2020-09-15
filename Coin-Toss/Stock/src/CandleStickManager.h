#pragma once
#include "CandleStick.h"
#include "StockQue.h"
#include "vector"

namespace Stock {
	struct CandleStickData {
	private:
	public:
		unsigned int csd_tickInterval;
		unsigned int csd_curTick;
		std::vector<CandleStick>csd_candleSticks;
		CandleStickData(float openingPrice, unsigned int tickInterval, unsigned int numRuns) : csd_tickInterval(tickInterval), csd_curTick(0) {
			csd_candleSticks.reserve(numRuns); 
			csd_candleSticks.emplace_back(CandleStick(openingPrice));
		}
	protected:
	};

	class CandleStickManager {
	private:
		std::vector<CandleStickData>csm_candleSticks;
		unsigned int csm_numRuns;
		unsigned int csm_numRecord;
	public:
		CandleStickManager(float, float, unsigned int, std::vector<unsigned int>&);
		void updateCandleSticks(const StockQue&, const StockQue&);

	protected:

	};
}


