#include "CandleStick.h"

Stock::CandleStick::CandleStick() :cs_maxPrice(0), cs_minPrice(0), cs_openPrice(0), cs_closePrice(0),
cs_tickInterval(0), cs_tickTime(0) {}

Stock::CandleStick::CandleStick(float max_price, float min_price,int interval) : cs_maxPrice(max_price), cs_minPrice(min_price), cs_openPrice(max_price), cs_closePrice(0),
cs_tickInterval(interval), cs_tickTime(0) {}

//maxPrice, minPrice : updates candlestick
void Stock::CandleStick::updateCandleStick(const Stock::StockQue& current, const Stock::StockQue& previous) {
	HighLowPrice price = traded_price(current, previous);
	//comparing tick interval and resetting it
	if (cs_tickTime > cs_tickInterval) {
		cs_openPrice = cs_closePrice;
		cs_minPrice = cs_openPrice;
		cs_maxPrice = cs_openPrice;
		cs_closePrice = 0;
		cs_tickTime = 0;
	}
	else {
		if (price.changes) {
			//if traded price is lower than previous records
			if (price.lowestPrice < cs_minPrice) {
				cs_minPrice = price.lowestPrice;
			}
			//if traded price is bigger than previous records
			if (price.highestPrice > cs_maxPrice) {
				cs_maxPrice = price.highestPrice;
			}
			//closing price is always the latest trade - assumes median
			cs_closePrice = (price.highestPrice+price.lowestPrice)/2;
		}
	}
	cs_tickTime++;
	return;
};

Stock::CandleStick::~CandleStick() {}

static HighLowPrice traded_price(const Stock::StockQue& current, const Stock::StockQue& previous) {
	//determine difference in price
	float buy_pdiff = current.mq_topPrice_B[0] - previous.mq_topPrice_B[0];
	float sell_pdiff = current.mq_topPrice_S[0] - previous.mq_topPrice_S[0];

	HighLowPrice prices;
	
	//if price did not change
	if (!buy_pdiff && !sell_pdiff) {
		//determine difference in volume
		unsigned int buy_vdiff = current.mq_topVol_B[0] - previous.mq_topPrice_B[0];
		unsigned int sell_vdiff = current.mq_topVol_S[0] - previous.mq_topPrice_S[0];
		if (buy_vdiff < 0) {
			prices.lowestPrice = current.mq_topPrice_B[0];
		}
		if (sell_vdiff < 0) {
			prices.highestPrice =  current.mq_topPrice_S[0];
		}
		else {
			prices.changes = false;
		}
	}
	//if price changes
	else {
		//logic for when both price goes up
		if (buy_pdiff > 0 && sell_pdiff > 0) {
			prices.highestPrice = current.mq_topPrice_B.front();
			prices.lowestPrice = previous.mq_topPrice_S.front();
			for (unsigned int i = 0; i < previous.mq_size; i++) {
				if (current.mq_topPrice_B.front() < previous.mq_topPrice_S[i]) {
					prices.highestPrice = previous.mq_topPrice_S[i-1];
					break;
				}
			}
		}
		//logic for when both price goes down
		else if (buy_pdiff < 0 && sell_pdiff < 0) {
			prices.highestPrice = previous.mq_topPrice_B.front();
			prices.lowestPrice = current.mq_topPrice_S.front();
			for (unsigned int i = 0; i < previous.mq_size; i++) {
				if (current.mq_topPrice_S.front() > previous.mq_topPrice_B[i]) {
					prices.lowestPrice = current.mq_topPrice_S[i - 1];
					break;
				}
			}
		}
		//if buy is going down and sell is going up * MIGHT NEED REVIEW
		else if (buy_pdiff < 0 && sell_pdiff>0) {
			prices.highestPrice = current.mq_topPrice_S.front();
			prices.lowestPrice = current.mq_topPrice_B.back();
		}
		//logic for price "filling"
		else if (buy_pdiff > 0 || sell_pdiff < 0) {
			prices.changes = false;
		}
		//logic for buy price going down
		else if (buy_pdiff < 0) {
			prices.highestPrice = previous.mq_topPrice_B.front();
			prices.lowestPrice = previous.mq_topPrice_B.back();
			for (unsigned int i = 0; i < previous.mq_size; i++) {
				if (current.mq_topPrice_B.front() > previous.mq_topPrice_B[i]) {
					prices.lowestPrice = previous.mq_topPrice_B[i-1];
					break;
				}
			}
		}
		//logic for sell price going up
		else if (sell_pdiff > 0){
			prices.highestPrice = previous.mq_topPrice_S.back();
			prices.lowestPrice = previous.mq_topPrice_S.front();
			for (unsigned int i = 0; i < previous.mq_size; i++) {
				if (current.mq_topPrice_S.front() < previous.mq_topPrice_S[i]) {
					prices.highestPrice = previous.mq_topPrice_S[i - 1];
					break;
				}
			}
		}
		
	}
	return prices;
}
