#include "CandleStickManager.h"
#include <iostream>

Stock::CandleStickManager::CandleStickManager(float min_price, float max_price, unsigned int numRuns, std::vector<unsigned int>& cs_intervals)
	: csm_numRuns(numRuns), csm_numRecord(cs_intervals.size()) {
	csm_candleSticks.reserve(cs_intervals.size());
	for (unsigned int i = 0; i < cs_intervals.size(); i++) {
		csm_candleSticks.emplace_back(CandleStickData(max_price, cs_intervals[i], numRuns));
	}
}

void Stock::CandleStickManager::updateCandleSticks(const Stock::StockQue& current, const Stock::StockQue& previous) {
	for (auto candlesticks = csm_candleSticks.begin(); candlesticks != csm_candleSticks.end(); candlesticks++) {
		if (candlesticks->csd_curTick >= candlesticks->csd_tickInterval) {
			if (candlesticks->csd_candleSticks.size() < csm_numRuns) {
				candlesticks->csd_candleSticks.emplace_back(CandleStick(candlesticks->csd_candleSticks[candlesticks->csd_candleSticks.size()-1].getClosePrice()));
			}
			else {
				for (unsigned int i = (candlesticks->csd_candleSticks.size() - 1); i > 0; i--) {
					candlesticks->csd_candleSticks[i] = candlesticks->csd_candleSticks[i - 1];
				}
				candlesticks->csd_candleSticks[0] = CandleStick(candlesticks->csd_candleSticks[1].getClosePrice());
			}
			candlesticks->csd_curTick = 0;
		}
		else {
			candlesticks->csd_candleSticks[0].updateCandleStick(current, previous);
			candlesticks->csd_curTick++;
		}
		for (auto candlestick = candlesticks->csd_candleSticks.begin(); candlestick != candlesticks->csd_candleSticks.end(); candlestick++) {
			std::cout << candlestick->getClosePrice() << std::endl;
		}
		
	}
}