#include "DataManager.h"
#include "Stock.h"
#include <iostream>

int main() {
	std::vector<Stock::Stock> stocks;
	Data::DataManager datamanager(stocks);
	for (int i = 0; i < 50; i++) {
		datamanager.updateData(stocks);
	}
	
}