#include "Stock.h"
#include <iostream>

template <size_t size>
Stock::Stock<size>::Stock(const std::string& stockID, std::array<float, size>& topCurPrice_B, std::array<float, size>& topCurPrice_S,
	std::array<unsigned int, size>& topCurVol_B, std::array<unsigned int, size>& topCurVol_S, unsigned int totalVol)
	:s_stockID(stockID), s_topCurPrice_B(&topCurPrice_B), s_topCurPrice_S(&topCurPrice_S), s_topCurVol_B(&topCurVol_B),
	s_topCurVol_S(&topCurVol_S), s_totalVol(totalVol) {

	std::array<float, size>* topPrevPrice_B = new std::array<float, size>(*s_topCurPrice_B);
	std::array<float, size>* topPrevPrice_S = new std::array<float, size>(*s_topCurPrice_S);
	std::array<unsigned int, size>* topPrevVol_B = new std::array<unsigned int, size>(*s_topCurVol_B);
	std::array<unsigned int, size>* topPrevVol_S = new std::array<unsigned int, size>(*s_topCurVol_S);

	stockRecord = new StockRecord<size>(*topPrevPrice_B, *topPrevPrice_S, *topPrevVol_B, *topPrevVol_S);
};

template<size_t size>
Stock::Stock<size>::~Stock() {
	delete s_topCurPrice_B;
	delete s_topCurPrice_S;
	delete s_topCurVol_B;
	delete s_topCurVol_S;
};

//int main() {
//	const std::string stockID("001");
//	std::array<float, 3>* topCurPrice_B = new std::array<float, 3>{ 3,2,1 };
//	std::array<float, 3>* topCurPrice_S = new std::array<float, 3>{ 4,5,6 };
//	std::array<unsigned int, 3>* topCurVol_B = new std::array<unsigned int, 3> { 10,9,8 };
//	std::array<unsigned int, 3>* topCurVol_S = new std::array<unsigned int, 3> { 7,6,11 };
//	unsigned int totalvol = 1 + 2 + 3;
//
//	{
//		Stock::Stock<3> stock(stockID, *topCurPrice_B, *topCurPrice_S, *topCurVol_B, *topCurVol_S, totalvol);
//	}
//}