#include "Stock.h"

Data::Stock::Stock(const std::string& stockID, Data::DataSource* dataSource): stockID(stockID), dataSource(dataSource), curInfo(NULL), prevInfo(NULL){}

void Data::Stock::updateMe() {
	std::string temp;
	dataSource->readData(temp);
}