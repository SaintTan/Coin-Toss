#pragma once
#include "Stock.h"

namespace Analysis {
	namespace CandleStickAnalysis {
		bool detectBearishEngulfing();
		bool detectBearishEveningStar();
		bool detectBearishHarami();
		bool detectBearishHaramiCross();
		bool detectRisingThree();
		bool detectFallingThree();
	}
}

