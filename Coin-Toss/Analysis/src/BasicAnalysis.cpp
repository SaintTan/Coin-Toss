#include "BasicAnalysis.h"

float Analysis::BasicAnalysis::priceChanges(const Stock::StockQue& current, const Stock::StockQue& previous, const std::string& mode) {
	if (mode == "buy") return current.mq_topPrice_B[0] - previous.mq_topPrice_B[0];
	else if (mode == "sell") return current.mq_topPrice_S[0] - previous.mq_topPrice_S[0];
	else return 0; 
}

uint32_t Analysis::BasicAnalysis::volChanges(const Stock::StockQue& current, const Stock::StockQue& previous, const std::string& mode) {
	if (mode == "buy" && (previous.mq_topPrice_B[0] == current.mq_topPrice_B[0])) return previous.mq_topVol_B[0] - current.mq_topVol_B[0];
	else if (mode == "sell" && (previous.mq_topPrice_B[0] == current.mq_topPrice_B[0])) return previous.mq_topVol_S[0] - current.mq_topVol_S[0];
	else return 0;
}