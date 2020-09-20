#include "GetBestPrice.h"

PriceStrat::GetBestPrice::GetBestPrice(){}

float PriceStrat::GetBestPrice::getPrice(const Stock::StockQue& stockque, const std::string& mode) {
	if (mode == "buy") return stockque.mq_topPrice_B[0];
	else if (mode == "sell") return stockque.mq_topPrice_S[0];
	return 0.0f;
}