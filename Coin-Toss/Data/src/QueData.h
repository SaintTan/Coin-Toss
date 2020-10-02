#pragma once
#include "Data.h"
#include "Stock.h"
#include <fstream>
#include <vector>

static uint32_t getQueRowNum(const std::string& string); //string : returns the amount of rows of a stockque - for initializing purposes

namespace Data {
	struct DataPackageQue {
	private:
	public:
		const uint32_t dpq_num; //assign value for datastream
		Stock::StockQue dpq_stockque; //stockque
	public:
		DataPackageQue(uint32_t i, uint32_t stockqueNum) : dpq_num(i), dpq_stockque(stockqueNum) {}
	};

	class QueData : public Data {
	private:
		static std::wstring qd_location; //location of text file
		std::vector<DataPackageQue> qd_stockques; //holds stockque data
	private:
		void process_data(const std::string&, Stock::StockQue&) const; //string, stockque : converting string to numbers and updates the stockque
	public:
		QueData(uint32_t);
		static void getFileNames(std::vector<std::wstring>&); //filenames : returns the filenames inside the directory specified in qd_location
		Stock::StockQue* getStockQue(uint32_t); // i, returns a pointer to the stockque
		void updateData(); //i, stockque : updates data
		~QueData();
	protected:
	};
}


