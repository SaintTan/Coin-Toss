#include "Market.h"
#include "Broker.h"
#include <string>
#include <array>

template <size_t size>

class Market {
private:
	static int newMarketID;
	std::string marketID;
	std::array<Stocks, size> stocks;
	std::array<Broker, size> brokers;
public:
	Market(std::array<Stocks, size> stocks, array<Broker,size> brokers): stocks(stocks),brokers(brokers){
		marketID = getNewMarketID();
	}

	bool updateStock() {
		for (it = stocks.begin(); it != stocks.end(); it++) {
			
		}
		return true;
	}

protected:
	static int getNewMarketID() {
		return newMarketID++;
	}
};