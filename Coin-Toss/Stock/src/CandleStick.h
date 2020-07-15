#pragma once

namespace Stock {
	class IDManagement {
	private:
		static char currentID;
	public:
		IDManagement();
		static char getNewID();
	};

	class CandleStick {
	private:
		char cs_candleID;
		float cs_maxPrice, cs_minPrice, cs_openPrice, cs_closePrice;
		int cs_tickTime;
		int cs_tickInterval;
	public:
		CandleStick();
		CandleStick(float, float , int); //maxPrice, minPrice, tickInterval
		void updateCandleStick(float, float); //maxPrice, minPrice
		~CandleStick();
	protected:
	};
};




