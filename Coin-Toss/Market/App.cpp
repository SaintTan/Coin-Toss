#include "src/Market.h"
#include <iostream>

int main() {
	std::string id = "001";
	Market::Market market(id);
	market.updateStock();
}