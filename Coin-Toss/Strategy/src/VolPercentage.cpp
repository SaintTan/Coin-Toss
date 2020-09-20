#include "VolPercentage.h"
#include <iostream>

VolStrat::VolPercentage::VolPercentage(float percentage, unsigned int maxVol) : vp_percent(percentage),vp_maxVol(maxVol) {}

unsigned int VolStrat::VolPercentage::getVol(int curVol) {
	if (curVol < 1) {
		return 0;
	}
	int tradeVol = static_cast<int>(vp_maxVol * vp_percent);
	return tradeVol;
}

unsigned int VolStrat::VolPercentage::getVol_CurStock(const Market::OrderQue& orderQue, const std::string& mode) {
	int totalVol = 0;

	if (!orderQue.oq_confirmBuys.empty()) {
		for (auto order : orderQue.oq_confirmBuys) totalVol += order.o_volume;
	}
	
	if (mode == "buy") {	
		totalVol = vp_maxVol - totalVol;
	}

	return getVol(totalVol);
}