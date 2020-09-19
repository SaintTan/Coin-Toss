#include "VolPercentage.h"
#include <iostream>

VolStrat::VolPercentage::VolPercentage(float percentage, unsigned int maxVol) : vp_percent(percentage),vp_maxVol(maxVol) {}

unsigned int VolStrat::VolPercentage::getVol(unsigned int curVol) {
	unsigned int tradeVol = static_cast<unsigned int>(vp_maxVol * vp_percent);
	std::cout << "volume" << std::endl;
	if (curVol <= tradeVol) {
		std::cout << curVol << std::endl;
		return curVol;
	}
	else {
		std::cout << tradeVol << std::endl;
	}
	return tradeVol;
}

unsigned int VolStrat::VolPercentage::getVol_CurStock(const Market::OrderQue& orderQue, const std::string& mode) {
	unsigned int totalVol = 0;

	if (mode == "sell") {
		if (!orderQue.oq_confirmBuys.empty()) {
			for (auto order : orderQue.oq_confirmBuys) totalVol += order.o_volume;
		}
	}
	
	else if (mode == "buy") {
		if (!orderQue.oq_sent_ordersS.empty()) {
			for (auto order : orderQue.oq_sent_ordersS) totalVol += order.o_volume;
		}
	}
	std::cout << "totalVol" << std::endl;
	std::cout << totalVol << std::endl;

	if (totalVol >= vp_maxVol) return 0;

	return getVol(vp_maxVol-totalVol);
}