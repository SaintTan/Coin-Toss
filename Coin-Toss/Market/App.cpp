#include "Stock.h"
#include "MarketQue.h"
#include <string>
#include <array>

int main() {
	const std::string stockID = "001";
	Stock::MarketQue<3> topPrices;
	std::array<float, 3> topCurPrice_B = { 3,2,1 };
	std::array<float, 3> topCurPrice_S = { 4,5,6 };
	topPrices.s_topPrice_B = topCurPrice_B;
	topPrices.s_topPrice_S = topCurPrice_S;
	std::array<unsigned int, 3> topCurVol_B = { 10,11,12 };
	std::array<unsigned int, 3> topCurVol_S = { 13,14,15 };
	topPrices.s_topVol_B = topCurVol_B;
	topPrices.s_topVol_S = topCurVol_S;
	std::array<unsigned int, 5> cs_Interval = { 100,300,1000 };
	unsigned int totalVol= 3+2+1+4+5+6;
	Stock::Stock<3, 5> first_stock(stockID, topPrices, cs_Interval, totalVol);
}