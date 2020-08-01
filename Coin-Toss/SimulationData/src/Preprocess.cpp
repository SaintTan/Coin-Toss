#include "Preprocess.h"

static void getFilesLoc(const std::wstring& source, std::vector<std::wstring>& const fileLocNames) {
    LPTSTR buffer = new TCHAR[BUFFSIZE];
    getCurrentLoc(buffer);
    std::wstring datasource(buffer);
    datasource.append(L"\\data\\").append(source);
    fileLocNames.reserve(readInLocFilesNum(datasource));
    readInLocFilesEntry(datasource, fileLocNames);
    delete[] buffer;
    return;
}

static int readInLocFilesNum(const std::wstring& fileLocName) {
    int numEntry = 0;
    std::wstring line;
    std::wifstream file;
    file.open(fileLocName);
    if (file.is_open()) {
        while (std::getline(file, line)) {
            numEntry++;
        }
    }
    return numEntry;
}

static void readInLocFilesEntry(const std::wstring& fileLocName, std::vector<std::wstring>& fileLocNames) {
    std::wstring line;
    std::wifstream file;
    file.open(fileLocName);
    if (file.is_open()) {
        while (std::getline(file, line)) {
            fileLocNames.emplace_back(line.append(L"\\*"));
        }
    }
    return;
}

void getDataFiles(const std::wstring& source, std::vector<std::ifstream>& filenames) {
    std::vector<std::wstring> fileLocNames;
    getFilesLoc(source, fileLocNames);
    for (auto it = fileLocNames.begin(); it != fileLocNames.end(); it++) {
        filenames.reserve(getDataNum(*it));
    }
    for (auto it = fileLocNames.begin(); it != fileLocNames.end(); it++) {
        getDataFilesEntry(*it, filenames);
    }
    return;
}

static int getDataNum(const std::wstring& fileLoc) {
    int numEntry = 0;
    WIN32_FIND_DATA data;
    HANDLE hFind;
    if ((hFind = FindFirstFile(fileLoc.c_str(), &data)) != INVALID_HANDLE_VALUE) {
        do {
            numEntry++;
        } while (FindNextFile(hFind, &data) != 0);
        FindClose(hFind);
    }
    return numEntry-2;
}

static void getDataFilesEntry(const std::wstring& fileLoc, std::vector<std::ifstream>& datastream) {
    int removeDots = 0;
    WIN32_FIND_DATA data;
    HANDLE hFind;
    if ((hFind = FindFirstFile(fileLoc.c_str(), &data)) != INVALID_HANDLE_VALUE) {
        do {
            if (removeDots<2) {
                removeDots++;
                continue;
            }
            std::wstring fileDestination(fileLoc);
            fileDestination.pop_back();
            datastream.emplace_back(std::ifstream(fileDestination.append(data.cFileName)));
        } while (FindNextFile(hFind, &data) != 0);
        FindClose(hFind);
    }
}

void getDataFilesName(const std::wstring& source, std::vector<std::wstring>& filenames) {
    std::vector<std::wstring> fileLocNames;
    getFilesLoc(source, fileLocNames);
    for (auto it = fileLocNames.begin(); it != fileLocNames.end(); it++) {
        filenames.reserve(getDataNum(*it));
    }
    for (auto it = fileLocNames.begin(); it != fileLocNames.end(); it++) {
        int removeDots = 0;
        WIN32_FIND_DATA data;
        HANDLE hFind;
        if ((hFind = FindFirstFile((*it).c_str(), &data)) != INVALID_HANDLE_VALUE) {
            do {
                if (removeDots < 2) {
                    removeDots++;
                    continue;
                }
                filenames.emplace_back(data.cFileName);
            } while (FindNextFile(hFind, &data) != 0);
            FindClose(hFind);
        }
    }
}

static bool getCurrentLoc(const LPTSTR& buffer) {
    DWORD dwRet;
    dwRet = GetCurrentDirectory(BUFFSIZE, buffer);

    if (dwRet == 0 || dwRet > BUFFSIZE) {
        return false;
    }

    return true;
}
