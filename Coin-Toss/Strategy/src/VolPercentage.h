#pragma once
#include "Order.h"
#include <string>

namespace VolStrat {
	class VolPercentage {
	private:
		float vp_percent;
		uint32_t vp_maxVol;
	public:
		VolPercentage(float, uint32_t);
		uint32_t getVol(int);
		uint32_t getVol_CurStock(const Market::OrderQue&, const std::string&);

	protected:
	};
}