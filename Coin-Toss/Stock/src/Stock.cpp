#include "Stock.h"
#include <iostream>

template <size_t size, size_t size_cs>
Stock::Stock<size, size_cs>::Stock(const std::string& stockID, std::array<float, size>& topCurPrice_B, std::array<float, size>& topCurPrice_S,
	std::array<unsigned int, size>& topCurVol_B, std::array<unsigned int, size>& topCurVol_S, std::array<int, size_cs>& csInterval, unsigned int totalVol)
	:s_stockID(stockID), s_topCurPrice_B(&topCurPrice_B), s_topCurPrice_S(&topCurPrice_S), s_topCurVol_B(&topCurVol_B),	s_topCurVol_S(&topCurVol_S), 
	s_stockRecord(StockRecord<size, size_cs>(csInterval)), s_totalVol(totalVol) {};

template<size_t size, size_t size_cs>
void Stock::Stock<size, size_cs>::updateStock(int totalVol) {
	s_totalVol = totalVol;
	s_stockRecord.updateStockRecord(*s_topCurPrice_B, *s_topCurPrice_S, *s_topCurVol_B, *s_topCurVol_S);
}

template<size_t size, size_t size_cs>
Stock::Stock<size, size_cs>::~Stock() {
	s_stockRecord.~StockRecord();
};

//int main() {
//	const std::string stockID("001");
//	std::array<float, 3> topCurPrice_B{ 3,2,1 };
//	std::array<float, 3> topCurPrice_S{ 4,5,6 };
//	std::array<unsigned int, 3>topCurVol_B{ 10,9,8 };
//	std::array<unsigned int, 3>topCurVol_S{ 7,6,11 };
//	std::array<int, 5>intervals{ 4,5,6,7,8 };
//	unsigned int totalvol = 1 + 2 + 3;
//
//	{ 
//		{
//			Stock::Stock<3, 5>* stock = new Stock::Stock<3,5>(stockID, topCurPrice_B, topCurPrice_S, topCurVol_B, topCurVol_S, intervals, totalvol);
//			Stock::Stock<3, 5>* stock1 = new Stock::Stock<3, 5>(stockID, topCurPrice_B, topCurPrice_S, topCurVol_B, topCurVol_S, intervals, totalvol);
//			Stock::Stock<3, 5>* stock2 = new Stock::Stock<3, 5>(stockID, topCurPrice_B, topCurPrice_S, topCurVol_B, topCurVol_S, intervals, totalvol);
//			topCurPrice_B = { 13,12,11 };
//			topCurPrice_S = { 14,15,16 };
//			topCurVol_B = { 20,19,18 };
//			topCurVol_S = { 17,16,21 };
//			intervals = { 14,15,16,17,18 };
//			totalvol = 11 + 12 + 13;
//			(*stock).updateStock(totalvol);
//			delete stock;
//			delete stock1;
//			delete stock2;
//		}
//	}
//}