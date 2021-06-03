	#pragma once
#include "Stock.h"
#include "AVLTree.h"
#include <string>

namespace Data {
	class Market {
	private:
		DataStruct::AVLTree<Data::Stock> stocks;
	public:
		Market(Data::Stock&);
		Market(const std::string& stockID, Data::DataSource* dataSource);
		void updateStocks();
	};
}


