#pragma once
class IDManagement {
private:
	static char currentID;
public:
	IDManagement();
	static char getNewID();
};

class CandleStick{
private:
	char cs_candleID;
	float cs_maxPrice, cs_minPrice, cs_openPrice, cs_closePrice;
	float cs_timeInterval;
public:
	CandleStick(float);
protected:
};


