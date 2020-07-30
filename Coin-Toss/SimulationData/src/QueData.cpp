#include "QueData.h"

std::wstring Data::QueData::location = L"QueData.txt";

Data::QueData::QueData():Data(location){}

void Data::QueData::updateData(unsigned int i, Stock::Stock& const stock) {
	
}

Data::QueData::~QueData() {}