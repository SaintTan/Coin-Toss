#include "Preprocessing.h"

static void getData(const std::wstring& fileLoc, std::vector<std::wstring>& const filenames) {
    
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
    return numEntry;
}

static void getFilesLoc(std::vector<std::wstring>& const fileLocNames) {
    LPTSTR buffer = new TCHAR[BUFFSIZE];
    getCurrentLoc(buffer);
    std::wstring datasource(buffer);
    datasource.append(L"\\data\\datasource.txt");
    fileLocNames.reserve(readInLocFilesNum(datasource));
    readInLocFilesEntry(datasource, fileLocNames);
    delete[] buffer;
    return;
}

static int readInLocFilesNum(const std::wstring& fileLocName) {
    int numEntry = 0;
    std::wstring line;
    std::wifstream file;
    std::wcout << fileLocName << std::endl;
    file.open(fileLocName);
    std::cout << file.is_open() << std::endl;
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
    std::wcout << fileLocName << std::endl;
    file.open(fileLocName);
    std::cout << file.is_open() << std::endl;
    if (file.is_open()) {
        while (std::getline(file, line)) {
            fileLocNames.emplace_back(line.append(L"\\*"));
        }
    }
    return;
}

static bool getCurrentLoc(const LPTSTR& buffer) {
    DWORD dwRet;
    dwRet = GetCurrentDirectory(BUFFSIZE, buffer);

    if (dwRet == 0 || dwRet > BUFFSIZE) {
        return false;
    }

    return true;
}