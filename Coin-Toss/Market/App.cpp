#include "src/Market.h"
#include <iostream>

int main() {
	std::string id = "001";
	//starts market components
	Market::Market market(id);
	//updates data
	for (int i = 0; i < 30810; i++) {
		std::cout << i << std::endl;
		market.updateStock();
	}
}