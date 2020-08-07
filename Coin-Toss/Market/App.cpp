#include "src/Market.h"
#include <iostream>

int main() {
	std::string id = "001";
	//starts market components
	Market::Market market(id);
	//updates data
	for (int i = 0; i < 1000; i++) {
		market.updateStock();
	}
}