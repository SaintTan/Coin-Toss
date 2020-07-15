#include "Stock.h"
#include <string>
#include <array>

int main() {
	const std::string stockID = "001";
	std::array<float, 3> topCurPrice_B = { 3,2,1 };
	std::array<float, 3> topCurPrice_S = { 4,5,6 };
	std::array<unsigned int, 3> topCurVol_B = { 10,11,12 };
	std::array<unsigned int, 3> topCurVol_S = { 13,14,15 };
	std::array<unsigned int, 5> cs_Interval = { 100,300,1000 };
	unsigned int totalVol= 3+2+1+4+5+6;
	Stock::Stock<3, 5> first_stock(stockID, topCurPrice_B, topCurPrice_S, topCurVol_B, topCurVol_S, cs_Interval, totalVol);
}