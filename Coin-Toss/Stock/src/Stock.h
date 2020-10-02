#pragma once
#include "CandleStickManager.h"
#include "StockRecord.h"
#include "StockQue.h"
#include <string>
#include <queue>
#include <vector>

static uint32_t getTotalVol(const Stock::StockQue& stockque); //calculates the total amount of volume inside the stock que

namespace Stock {
	class Stock {
	private:
		std::wstring s_stockID; //ID of stock - also stock symbol
		const StockQue* s_topCur; //stockque
		StockRecord s_stockRecord; //previous stockrecord
		CandleStickManager s_candleStickManager; //candle stick with different intervals
		uint32_t s_totalVol; //total volume of stockque
	private:
	public:
		Stock(const std::wstring&, StockQue&, std::vector<uint32_t>&); //stockID, s_topCur, cs_interval
		void updateStockQue1(); //updates stockRecordd and candlesticks
		void updateStockQue2(); //updates totalVol
		std::wstring get_stockID() const; //returns stockID
		const StockRecord* getStockRecord() const; //returns stockRecord 
		const StockQue* getStockQue() const; //returns stockQue
		~Stock();
	protected:
	};
}