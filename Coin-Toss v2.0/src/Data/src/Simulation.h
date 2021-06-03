#pragma once
#include "DataSource.h"
#include <string>
#include <fstream>

namespace Data {
	class Simulation :public DataSource {
	private:
		std::ifstream readFile;
	public:
		Simulation(const std::string& fileLoc, const std::string& fileName);
		Simulation(const std::string& file);

		void readData(std::string& temp) override;
	};
}

