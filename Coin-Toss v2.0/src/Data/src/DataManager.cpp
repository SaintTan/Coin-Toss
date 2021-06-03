#include "DataManager.h"
#include "Simulation.h"
#include "RealTime.h"

void updateMarket(Data::Market& market);

Data::DataManager::DataManager(Data::FileType filetype, const std::string& loc, const std::string& name): markets(*(new Market(loc+name, DataSourceFactory(filetype, loc+name)))){}

Data::DataManager::DataManager(Data::FileType filetype, const std::string& name): markets(*(new Market(name, DataSourceFactory(filetype, name)))){}

void Data::DataManager::updateData() {
	markets.workTree(updateMarket);
}

Data::DataSource* Data::DataManager::DataSourceFactory(Data::FileType filetype, const std::string& loc, const std::string& name) {
	if (filetype == Data::FileType::RealTime) {
		return new Data::RealTime(loc + name);
	}
	return new Data::Simulation(loc + name);
}
Data::DataSource* Data::DataManager::DataSourceFactory(Data::FileType filetype, const std::string& name) {
	if (filetype == Data::FileType::RealTime) {
		return new Data::RealTime(name);
	}
	return new Data::Simulation(name);
}

void updateMarket(Data::Market& market) {
	market.updateStocks();
}

