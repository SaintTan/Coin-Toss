#include "CandleStick.h"

Stock::CandleStick::CandleStick() :cs_maxPrice(0), cs_minPrice(0), cs_openPrice(0), cs_closePrice(0),
cs_tickInterval(0), cs_tickTime(0) {}

Stock::CandleStick::CandleStick(float max_price, float min_price,int interval) : cs_maxPrice(max_price), cs_minPrice(min_price), cs_openPrice(max_price), cs_closePrice(0),
cs_tickInterval(interval), cs_tickTime(0) {}

//maxPrice, minPrice : updates candlestick *NEEDS REVISION
void Stock::CandleStick::updateCandleStick(const Stock::StockQue& current, const Stock::StockQue& previous) {
	HighLowPrice price = traded_price(current, previous);
	if (cs_tickTime > cs_tickInterval) {
		cs_openPrice = cs_closePrice;
		cs_minPrice = cs_openPrice;
		cs_maxPrice = cs_openPrice;
		cs_closePrice = 0;
		cs_tickTime = 0;
	}
	else {
		if (price.lowestPrice < cs_minPrice) {
			cs_minPrice = price.lowestPrice;
		}
		if (price.highestPrice > cs_maxPrice) {
			cs_maxPrice = price.highestPrice;
		}
		cs_closePrice = price.highestPrice;
	}
	std::cout << cs_minPrice << "," << cs_maxPrice << "," << cs_openPrice << "," << cs_closePrice <<std::endl;
	cs_tickTime++;
	return;
};

Stock::CandleStick::~CandleStick() {}

static HighLowPrice traded_price(const Stock::StockQue& current, const Stock::StockQue& previous) {
	//determine difference in price
	float buy_pdiff = current.mq_topPrice_B[0] - previous.mq_topPrice_B[0];
	float sell_pdiff = current.mq_topPrice_S[0] - previous.mq_topPrice_S[0];
	unsigned int buy_vdiff = current.mq_topVol_B[0] - previous.mq_topPrice_B[0];
	unsigned int sell_vdiff = current.mq_topVol_S[0] - previous.mq_topPrice_S[0];
	if (!buy_pdiff && !sell_pdiff) {
		HighLowPrice prices(current.mq_topPrice_B[0], current.mq_topPrice_S[0]);
		if (!buy_vdiff && !sell_vdiff) {
			prices.changes = false;
		}
		else if (!buy_vdiff) {
			prices.highestPrice = prices.lowestPrice = current.mq_topPrice_B[0];
		}
		else if (!sell_vdiff) {
			prices.highestPrice = prices.lowestPrice = current.mq_topPrice_S[0];
		}
		return prices;
	}
	else {
		HighLowPrice prices(current.mq_topPrice_B[0] + 0.1f, current.mq_topPrice_S[0] - 0.1f);
		if (buy_pdiff > 0 && sell_pdiff > 0) {
			prices.lowestPrice = previous.mq_topPrice_B[0] + 0.1f;
			prices.highestPrice = current.mq_topPrice_S[0] - 0.1f;
		}
		else if (buy_pdiff < 0 && sell_pdiff < 0) {
			prices.lowestPrice = current.mq_topPrice_B[0] + 0.1f;
			prices.highestPrice = previous.mq_topPrice_S[0] - 0.1f;
		}
		return prices;
	}
}