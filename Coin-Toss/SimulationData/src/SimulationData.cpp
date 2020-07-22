#include "SimulationData.h"

static std::wstring convert_To_Wstring(const std::string&);

SimulationData::SimulationData::SimulationData(const std::string& pathDir) : sd_pathDir(pathDir), sd_filenum(0) {
    sd_filenum = getFileAmount();
};

unsigned int SimulationData::SimulationData::getFileAmount() {
    unsigned int amount = 0;
	WIN32_FIND_DATA data;
    std::wstring temp_pathDir = convert_To_Wstring(sd_pathDir);
	LPCWSTR wtemp_pathDir = temp_pathDir.c_str();
	HANDLE find = FindFirstFile(wtemp_pathDir, &data);

    if (find != INVALID_HANDLE_VALUE) {
        amount += 1;
        while (FindNextFile(find, &data)) {
            amount += 1;
        }
        FindClose(find);
    }
    return amount;
}

void SimulationData::SimulationData::getFileNames() {}

static std::wstring convert_To_Wstring(const std::string& string) {
    int len;
    int slength = (int)string.length() + 1;
    len = MultiByteToWideChar(CP_ACP, 0, string.c_str(), slength, 0, 0);
    wchar_t* buff = new wchar_t[len];
    MultiByteToWideChar(CP_ACP, 0, string.c_str(), slength, buff, len);
    std::wstring result(buff);
    delete[] buff;
    return result;
}