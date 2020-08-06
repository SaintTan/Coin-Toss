#include "QueData.h"

std::wstring Data::QueData::qd_location = L"StockQue_Source.txt";

Data::QueData::QueData():Data(qd_location){}

//string, stockque : converting string to numbers and updates the stockque
void Data::QueData::process_data(const std::string& string, Stock::StockQue& stockque) const {
	//holds current string
	std::string tempString = string;
	//get position of a string to cut
	std::size_t tempNum;
	//temporary string to convert to a number
	std::string tempStr;
	for (unsigned int i = 0; i < stockque.mq_size; i++) {
		//gets buy price
		tempNum = tempString.find(',');
		tempStr = tempString.substr(0, tempNum++);
		tempString.erase(0, tempNum);
		stockque.mq_topPrice_B[i] = std::stof(tempStr);
		//gets buy volume
		tempNum = tempString.find(',');
		tempStr = tempString.substr(0, tempNum++);
		tempString.erase(0, tempNum);
		stockque.mq_topVol_B[i] = std::stoul(tempStr);
		//gets sell price
		tempNum = tempString.find(',');
		tempStr = tempString.substr(0, tempNum++);
		tempString.erase(0, tempNum);
		stockque.mq_topPrice_S[i] = std::stof(tempStr);
		//gets sell volume
		tempNum = tempString.find(';');
		tempStr = tempString.substr(0, tempNum++);
		tempString.erase(0, tempNum);
		stockque.mq_topVol_S[i] = std::stoul(tempStr);
	}
}

//returns the filenames inside the directory specified in qd_location
void Data::QueData::getFileNames(std::vector<std::wstring>& filenames){
	this->getDataNames(qd_location, filenames);
}

//i, stockque : updates data
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

Data::QueData::~QueData() {}

//returns the amount of rows of a stockque - for initializing purposes
static unsigned int getQueRowNum(const std::string& string) {
	unsigned int rowNum = 0;
	for (std::string::const_iterator it = string.begin(); it != string.end(); it++) {
		if (*it == ';') {
			rowNum++;
		}
	}
	return rowNum;
}