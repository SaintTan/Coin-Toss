#include "Trader.h"

Market::Trader::Trader(double totalBal, const std::vector<TraderStockPage>& stocks): t_currentBal(totalBal), t_profitLoss(0){
	t_stockpages.reserve(stocks.size());
	for (auto stock = stocks.begin(); stock != stocks.end(); stock++) {
		t_stockpages.emplace_back(*stock);
	}
}

Market::Trader::sendBuyOrder