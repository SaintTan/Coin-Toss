#include "SimulationData.h"

static std::wstring convert_To_Wstring(const std::string&);

SimulationData::SimulationData::SimulationData(const std::string& pathDir) : sd_pathDir(pathDir), sd_filenum(0) {
    sd_filenum = getFileAmount();
};

unsigned int SimulationData::SimulationData::getFileAmount() {
    unsigned int amount = 0;
    std::string currentDir(GetCurrentDirectory()
    return amount;
}

void SimulationData::SimulationData::getFileNames() {}
