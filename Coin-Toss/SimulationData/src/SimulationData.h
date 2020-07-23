#pragma once
#include <string>
#include <vector>

namespace SimulationData{
	class SimulationData {
	private:
		unsigned int getFileAmount();
		void getFileNames();
	public:
		SimulationData();
	protected:
		std::vector<std::string> sd_filenames;
		unsigned int sd_filenum;
	};
}


