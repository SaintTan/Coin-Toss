#pragma once

namespace Stock {

	class CandleStick {
	private:
		float cs_maxPrice, cs_minPrice, cs_openPrice, cs_closePrice; //prices of stock
		int cs_tickTime; //current tick
		int cs_tickInterval; //tick intervals
	public:
		CandleStick();
		CandleStick(float, float , int); //maxPrice, minPrice, tickInterval
		void updateCandleStick(float, float); //maxPrice, minPrice : updates candlestick *NEEDS REVISION
		~CandleStick();
	protected:
	};
};




