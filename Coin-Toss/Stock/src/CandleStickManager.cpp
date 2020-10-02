#include "CandleStickManager.h"

Stock::CandleStickManager::CandleStickManager(float min_price, float max_price, uint32_t numRuns, std::vector<uint32_t>& cs_intervals)
	: csm_numRuns(numRuns), csm_numRecord(cs_intervals.size()) {
	csm_candleSticks.reserve(cs_intervals.size());
	for (uint32_t i = 0; i < cs_intervals.size(); i++) {
		csm_candleSticks.emplace_back(CandleStickData(max_price, cs_intervals[i], numRuns));
	}
}

void Stock::CandleStickManager::updateCandleSticks(const Stock::StockQue& current, const Stock::StockQue& previous) {
	for (auto candleData = csm_candleSticks.begin(); candleData != csm_candleSticks.end(); candleData++) {
		if (candleData->csd_curTick >= candleData->csd_tickInterval) {
			if (candleData->csd_candleSticks.size() < csm_numRuns) {
				candleData->csd_candleSticks.emplace_back(CandleStick(candleData->csd_candleSticks[candleData->csd_candleSticks.size()-1].getClosePrice()));
			}
			else {
				for (uint32_t i = (candleData->csd_candleSticks.size() - 1); i > 0; i--) {
					candleData->csd_candleSticks[i] = candleData->csd_candleSticks[i - 1];
				}
				candleData->csd_candleSticks[0] = CandleStick(candleData->csd_candleSticks[1].getClosePrice());
			}
			candleData->csd_curTick = 0;
		}
		else {
			candleData->csd_candleSticks[0].updateCandleStick(current, previous);
			candleData->csd_curTick++;
		}
		
	}
}