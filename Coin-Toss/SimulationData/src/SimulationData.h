#pragma once

#include <string>
#include <vector>

namespace SimulationData{
	class SimulationData {
	private:
	public:
		SimulationData();
	protected:
		std::vector<std::string> sd_filenames;
		unsigned int sd_filenum;
	};
}


