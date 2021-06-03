#include "Market.h"

void updateStock(Data::Stock& stock);

Data::Market::Market(Data::Stock& stock) :stocks(stock) {};

Data::Market::Market(const std::string& stockID, Data::DataSource* dataSource): stocks(*(new Stock(stockID, dataSource))){}

void updateStock(Data::Stock& stock) {
	stock.updateMe();
}

void Data::Market::updateStocks() {
	stocks.workTree(updateStock);
}
