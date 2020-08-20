#pragma once
#include "Analysis.h"
#include "Stock.h"
#include <queue>

class CandleStickAnalysis : public Analysis{
private:
	unsigned int timeInterval;
	std::queue<Stock::CandleStick> candleSticks;
public:
protected:
};

