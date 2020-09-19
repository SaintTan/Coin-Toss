#pragma once
#include "Order.h"
#include <string>

namespace VolStrat {
	class VolPercentage {
	private:
		float vp_percent;
		unsigned int vp_maxVol;
	public:
		VolPercentage(float, unsigned int);
		unsigned int getVol(unsigned int);
		unsigned int getVol_CurStock(const Market::OrderQue&, const std::string&);

	protected:
	};
}