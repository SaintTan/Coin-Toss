#pragma once
#include "StockInfo.h"
#include "DataSource.h"
#include <string>

namespace Data {
	class Stock {
	private:
		const std::string stockID;
		Data::DataSource* dataSource;
		const StockInfo* prevInfo;
		const StockInfo* curInfo;
	public:
		Stock(const std::string& stocckID, Data::DataSource* dataSource);
		void updateMe();
	};
}


