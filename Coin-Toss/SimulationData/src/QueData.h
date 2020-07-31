#pragma once
#include "Data.h"
#include <string>
#include <fstream>
#include <vector>

static unsigned int getQueRowNum(const std::string& string);

namespace Data {
	class QueData : public Data {
	private:
		static std::wstring qd_location;
		void process_data(const std::string&, Stock::StockQue& const);
	public:
		QueData();
		void getFileNames(std::vector<std::wstring>&);
		void initializeData(unsigned int i, Stock::StockQue&);
		void updateData(unsigned int i, Stock::StockQue& const);
		~QueData();
	protected:
	};
}


