#pragma once
#include "DataSource.h"
#include "Market.h"
#include "AVLTree.h"
#include <string>

namespace Data {
	enum class FileType {
		RealTime, Simulation
	};

	class DataManager {
	private:
		DataStruct::AVLTree<Market> market;
	public:
		DataManager(FileType, const std::string& loc, const std::string& name);
		DataManager(FileType, const std::string& name);
		void updateData();
	private:
		Data::DataSource* DataSourceFactory(FileType, const std::string& loc, const std::string& name);
		Data::DataSource* DataSourceFactory(FileType, const std::string& name);
	};
}


