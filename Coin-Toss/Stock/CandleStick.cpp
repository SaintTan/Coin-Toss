#include "CandleStick.h"
#include <iostream>

char IDManagement::currentID = 97;

IDManagement::IDManagement() {}

char IDManagement::getNewID() {
	return (char)currentID++;
}

CandleStick::CandleStick(float timeInterval)
	:cs_maxPrice(0), cs_minPrice(0), cs_openPrice(0), cs_closePrice(0),cs_timeInterval(timeInterval){
	cs_candleID= IDManagement::getNewID();
	std::cout << cs_candleID << std::endl;
}

