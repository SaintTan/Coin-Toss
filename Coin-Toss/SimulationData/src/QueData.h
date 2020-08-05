#pragma once
#include "Data.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

static unsigned int getQueRowNum(std::string& string);

namespace Data {
	class QueData : public Data {
	private:
		static std::wstring qd_location;
		void process_data(std::string&, Stock::StockQue&);
	public:
		QueData();
		void getFileNames(std::vector<std::wstring>&);
		void updateData(unsigned int, Stock::StockQue&);
		~QueData();
	protected:
	};
}


