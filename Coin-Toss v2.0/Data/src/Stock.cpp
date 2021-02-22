#include "Stock.h"

//formatting functions
static float convert_to_float(const std::string& temp);
static void format_SC(const std::string& data);

Data::Stock::Stock(const std::string& stockID, Data::DataSource* dataSource): stockID(stockID), dataSource(dataSource), curInfo(NULL), prevInfo(NULL){}

void Data::Stock::updateMe() {
	std::string temp;
	dataSource->readData(temp);
}

static float convert_to_float(const std::string& temp) {
	std::size_t found = temp.find(',');
	if (found) {
		return std::stof(temp.substr(0, found));
	}
	return std::stof(temp);
}

static void format_SC(const std::string& data) {
	while (data.find(',')) {
		convert_to_float(data);
	}
}