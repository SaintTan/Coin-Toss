#include "StockRecord.h"
#include <iostream>

template <size_t size>
StockRecord<size>::StockRecord(std::array<float, size>& topPrevPrice, std::array<unsigned int, size>& topPrevVol)
	:sr_topPrevPrice(&topPrevPrice), sr_topPrevVol(&topPrevVol){
}