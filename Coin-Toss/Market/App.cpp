#include "Stock.h"
#include "MarketQue.h"
#include <string>
#include <array>
#include <vector>

int main() {
	const std::string stockID = "001";
	Stock::MarketQue topPrices(3);
	std::vector<float> topCurPrice_B = { 3,2,1 };
	std::vector<float> topCurPrice_S = { 4,5,6 };
	topPrices.mq_topPrice_B = topCurPrice_B;
	topPrices.mq_topPrice_S = topCurPrice_S;
	std::vector<unsigned int> topCurVol_B = { 10,11,12 };
	std::vector<unsigned int> topCurVol_S = { 13,14,15 };
	topPrices.mq_topVol_B = topCurVol_B;
	topPrices.mq_topVol_S = topCurVol_S;
	std::vector<unsigned int> cs_Interval = { 100,300,1000 };
	unsigned int totalVol= 3+2+1+4+5+6;
	Stock::Stock first_stock(stockID, topPrices, cs_Interval, totalVol);
	totalVol = 100;
	first_stock.updateStock(totalVol);

	topCurPrice_B = { 13,12,11 };
	topCurPrice_S = { 14,15,16 };
	topCurVol_B = { 110,111,112 };
	topCurVol_S = { 113,114,115 };
	topPrices.mq_topPrice_B = topCurPrice_B;
	topPrices.mq_topPrice_S = topCurPrice_S;
	topPrices.mq_topVol_B = topCurVol_B;
	topPrices.mq_topVol_S = topCurVol_S;
}