#include "QueData.h"

std::wstring Data::QueData::qd_location = L"StockQue_Source.txt";

Data::QueData::QueData(unsigned int stockqueNum):Data(qd_location){
	qd_stockques.reserve(stockqueNum);
	for (unsigned int i = 0; i < stockqueNum; i++) {
		std::string string;
		this->getData(i, string);
		unsigned int rowNum = getQueRowNum(string);
		qd_stockques.emplace_back(DataPackageQue(i, rowNum));
		for (unsigned int j = 0; j < rowNum; j++) {
			qd_stockques[i].dpq_stockque.mq_topPrice_B.emplace_back();
			qd_stockques[i].dpq_stockque.mq_topVol_B.emplace_back();
			qd_stockques[i].dpq_stockque.mq_topPrice_S.emplace_back();
			qd_stockques[i].dpq_stockque.mq_topVol_S.emplace_back();
		}
		process_data(string, qd_stockques[i].dpq_stockque);
	}
}

//converting string to numbers and updates the stockque
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
		stockque.mq_topPrice_B[i] = std::stof(tempStr);
		tempString.erase(0, tempNum);
		//gets buy volume
		tempNum = tempString.find(',');
		tempStr = tempString.substr(0, tempNum++);
		stockque.mq_topVol_B[i] = std::stoul(tempStr);
		tempString.erase(0, tempNum);
		//gets sell price
		tempNum = tempString.find(',');
		tempStr = tempString.substr(0, tempNum++);
		stockque.mq_topPrice_S[i] = std::stof(tempStr);
		tempString.erase(0, tempNum);
		//gets sell volume
		tempNum = tempString.find(';');
		tempStr = tempString.substr(0, tempNum++);
		stockque.mq_topVol_S[i] = std::stoul(tempStr);
		tempString.erase(0, tempNum);
	}
}

//returns the filenames inside the directory specified in qd_location
void Data::QueData::getFileNames(std::vector<std::wstring>& filenames){
	Data::getDataNames(qd_location, filenames);
}

//returns pointer to the stockQue
Stock::StockQue* Data::QueData::getStockQue(unsigned int i) {
	return &qd_stockques[i].dpq_stockque;
}

//updates data
void Data::QueData::updateData() {
	for (auto stockque = qd_stockques.begin(); stockque != qd_stockques.end(); stockque++) {
		std::string string;
		this->getData(stockque->dpq_num, string);
		if (string == "") {
			for (unsigned int i = 0; i < stockque->dpq_stockque.mq_size; i++) {
				stockque->dpq_stockque.mq_topPrice_B[i] = 0;
				stockque->dpq_stockque.mq_topPrice_S[i] = 0;
				stockque->dpq_stockque.mq_topVol_B[i] = 0;
				stockque->dpq_stockque.mq_topVol_S[i] = 0;
				return;
			}
		}
		process_data(string, stockque->dpq_stockque);
	}
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