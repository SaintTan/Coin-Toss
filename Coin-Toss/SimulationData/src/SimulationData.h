#pragma once

#include "Stock.h"
#include <string>
#include <vector>

namespace SimulationData{
	struct datapackage {
	private:
	public:
		Stock::StockQue stockque;
		std::vector<std::ifstream> data;
	protected:
	};

	class SimulationData {
	private:
	public:
		SimulationData(std::vector<Stock::Stock>& const);
	protected:
		std::vector<std::string> sd_filenames;
		unsigned int sd_filenum;
	};
}


