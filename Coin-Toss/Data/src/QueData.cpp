#include "QueData.h"

std::wstring Data::QueData::qd_location = L"StockQue_Source.txt";

Data::QueData::QueData(uint32_t stockqueNum):Data(qd_location){
	//reserves number of stock
	qd_stockques.reserve(stockqueNum);
	//initialize stockque data
	for (uint32_t i = 0; i < stockqueNum; i++) {
		std::string string;
		this->getData(i, string);
		uint32_t rowNum = getQueRowNum(string);
		qd_stockques.emplace_back(DataPackageQue(i, rowNum));
		for (uint32_t j = 0; j < rowNum; j++) {
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

	for (uint32_t i = 0; i < stockque.mq_size; i++) {
		//gets buy price
		tempNum = tempString.find(',');
		stockque.mq_topPrice_B[i] = std::stof(tempString.substr(0, tempNum++));
		tempString.erase(0, tempNum);
		//gets buy volume
		tempNum = tempString.find(',');
		stockque.mq_topVol_B[i] = std::stoul(tempString.substr(0, tempNum++));
		tempString.erase(0, tempNum);
		//gets sell price
		tempNum = tempString.find(',');
		stockque.mq_topPrice_S[i] = std::stof(tempString.substr(0, tempNum++));
		tempString.erase(0, tempNum);
		//gets sell volume
		tempNum = tempString.find(';');
		stockque.mq_topVol_S[i] = std::stoul(tempString.substr(0, tempNum++));
		tempString.erase(0, tempNum);
	}
}

//returns the filenames inside the directory specified in qd_location
void Data::QueData::getFileNames(std::vector<std::wstring>& filenames){
	Data::getDataNames(qd_location, filenames);
}

//returns pointer to the stockQue
Stock::StockQue* Data::QueData::getStockQue(uint32_t i) {
	return &qd_stockques[i].dpq_stockque;
}

//updates data
void Data::QueData::updateData() {
	//loop through all active stockque
	for (auto stockque = qd_stockques.begin(); stockque != qd_stockques.end(); stockque++) {
		//gets string
		std::string string;
		this->getData(stockque->dpq_num, string);
		//checks for empty string
		if (string == "") {
			for (uint32_t i = 0; i < stockque->dpq_stockque.mq_size; i++) {
				stockque->dpq_stockque.mq_topPrice_B[i] = 0;
				stockque->dpq_stockque.mq_topPrice_S[i] = 0;
				stockque->dpq_stockque.mq_topVol_B[i] = 0;
				stockque->dpq_stockque.mq_topVol_S[i] = 0;
				return;
			}
		}
		//processes data
		process_data(string, stockque->dpq_stockque);
	}
}

Data::QueData::~QueData() {}

//returns the amount of rows of a stockque - for initializing purposes
static uint32_t getQueRowNum(const std::string& string) {
	uint32_t rowNum = 0;
	for (std::string::const_iterator it = string.begin(); it != string.end(); it++) {
		if (*it == ';') {
			rowNum++;
		}
	}
	return rowNum;
}