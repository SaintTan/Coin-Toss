#include "QueData.h"

std::wstring Data::QueData::qd_location = L"StockQue_Source.txt";

Data::QueData::QueData():Data(qd_location){}

void Data::QueData::getFileNames(std::vector<std::wstring>& filenames){
	this->getDataNames(qd_location, filenames);
}

void Data::QueData::updateData(unsigned int i, Stock::StockQue& stockque) {
	std::string string;
	this->getData(i, string);
	if (string == "") {
		for (unsigned int i = 0; i < stockque.mq_size; i++) {
			stockque.mq_topPrice_B[i] = 0;
			stockque.mq_topPrice_S[i] = 0;
			stockque.mq_topVol_B[i] = 0;
			stockque.mq_topVol_S[i] = 0;
			return;
		}
	}
	process_data(string, stockque);
}

void Data::QueData::process_data(const std::string& string, Stock::StockQue& stockque) const {
	std::string tempString = string;
	std::size_t tempNum;
	std::string tempStr;
	for (unsigned int i = 0; i < stockque.mq_size; i++) {
		tempNum = tempString.find(',');
		tempStr = tempString.substr(0, tempNum++);
		tempString.erase(0,tempNum);
		stockque.mq_topPrice_B[i]=std::stof(tempStr);
		tempNum = tempString.find(',');
		tempStr = tempString.substr(0, tempNum++);
		tempString.erase(0, tempNum);
		stockque.mq_topVol_B[i] = std::stoul(tempStr);
		tempNum = tempString.find(',');
		tempStr = tempString.substr(0, tempNum++);
		tempString.erase(0, tempNum);
		stockque.mq_topPrice_S[i] = std::stof(tempStr);
		tempNum = tempString.find(';');
		tempStr = tempString.substr(0, tempNum++);
		tempString.erase(0, tempNum);
		stockque.mq_topVol_S[i] = std::stoul(tempStr);
	}
}

Data::QueData::~QueData() {}

static unsigned int getQueRowNum(const std::string& string) {
	unsigned int rowNum = 0;
	for (std::string::const_iterator it = string.begin(); it != string.end(); it++) {
		if (*it == ';') {
			rowNum++;
		}
	}
	return rowNum;
}