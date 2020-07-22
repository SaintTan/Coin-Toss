#pragma once
#include <string>
#include <vector>
#include <windows.h>

namespace SimulationData{
	class SimulationData {
	private:
		unsigned int getFileAmount();
		void getFileNames();
	public:
		SimulationData(const std::string& pathDir);
	protected:
		std::string sd_pathDir;
		std::vector<std::string> sd_filenames;
		unsigned int sd_filenum;
	};
}


