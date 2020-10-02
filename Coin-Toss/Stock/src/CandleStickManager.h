#pragma once
#include "CandleStick.h"
#include "StockQue.h"
#include "vector"

namespace Stock {
	struct CandleStickData {
	private:
	public:
		uint32_t csd_tickInterval;
		uint32_t csd_curTick;
		std::vector<CandleStick>csd_candleSticks;
		CandleStickData(float openingPrice, uint32_t tickInterval, uint32_t numRuns) : csd_tickInterval(tickInterval), csd_curTick(0) {
			csd_candleSticks.reserve(numRuns); 
			csd_candleSticks.emplace_back(CandleStick(openingPrice));
		}
	protected:
	};

	class CandleStickManager {
	private:
		std::vector<CandleStickData>csm_candleSticks;
		uint32_t csm_numRuns;
		uint32_t csm_numRecord;
	public:
		CandleStickManager(float, float, uint32_t, std::vector<uint32_t>&);
		void updateCandleSticks(const StockQue&, const StockQue&);

	protected:

	};
}


