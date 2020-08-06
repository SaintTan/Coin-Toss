#pragma once
#include "Data.h"
#include <fstream>
#include <vector>

static unsigned int getQueRowNum(std::string& string); //string : returns the amount of rows of a stockque - for initializing purposes

namespace Data {
	class QueData : public Data {
	private:
		static std::wstring qd_location; //location of text file
		void process_data(const std::string&, Stock::StockQue&) const; //string, stockque : converting string to numbers and updates the stockque
	public:
		QueData();
		void getFileNames(std::vector<std::wstring>&); //filenames : returns the filenames inside the directory specified in qd_location
		void updateData(unsigned int, Stock::StockQue&); //i, stockque : updates data
		~QueData();
	protected:
	};
}


