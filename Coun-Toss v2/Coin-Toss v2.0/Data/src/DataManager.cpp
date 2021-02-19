#include "DataManager.h"
#include "Simulation.h"
#include "RealTime.h"

static float convert_to_float(const std::string& temp);
static void format_SC(const std::string& data);

Data::DataManager::DataManager(Data::FileType filetype, const std::string& loc, const std::string& name): market(*(new Market(loc+name, DataSourceFactory(filetype, loc+name)))){}

Data::DataManager::DataManager(Data::FileType filetype, const std::string& name): market(*(new Market(name, DataSourceFactory(filetype, name)))){}

void Data::DataManager::updateData() {
	std::string temp;
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

static float convert_to_float(const std::string& temp) {
	std::size_t found = temp.find(',');
	if (found) {
		return std::stof(temp.substr(0, found));
	}
	return std::stof(temp);
}

static void format_SC(const std::string& data) {
	while (data.find(',')) {
		convert_to_float(data);
	}
}