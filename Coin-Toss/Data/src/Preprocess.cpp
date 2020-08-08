#include "Preprocess.h"

//looks for files in the current directory inside the folder "data" and returns the file directories inside fileLocNames
static void getFilesLoc(const std::wstring& source, std::vector<std::wstring>& fileLocNames) {
    LPTSTR buffer = new TCHAR[BUFFSIZE];
    //get current location
    getCurrentLoc(buffer);
    //changging from LPTSTR to wstring
    std::wstring datasource(buffer);
    //looks for texts inside the "data" folder
    datasource.append(L"\\data\\").append(source);
    //reserving sizes
    fileLocNames.reserve(readInLocFilesNum(datasource));
    //inputing elements
    readInLocFilesEntry(datasource, fileLocNames);
    delete[] buffer;
    return;
}

//reads how many entries are there inside fileLocName - for initializing purposes
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
    file.close();
    return numEntry;
}

//reads in data and return it in fileLoc Names
static void readInLocFilesEntry(const std::wstring& fileLocName, std::vector<std::wstring>& fileLocNames) {
    std::wstring line;
    std::wifstream file;
    file.open(fileLocName);
    if (file.is_open()) {
        while (std::getline(file, line)) {
            //appending \* at the end for windows.h to know to read the actual files
            fileLocNames.emplace_back(line.append(L"\\*"));
        }
    }
    file.close();
    return;
}

//reads in from source and inputs it inside datastream, used to read multiple files
void getDataFiles(const std::wstring& source, std::vector<std::ifstream>& datastreams) {
    std::vector<std::wstring> fileLocNames;
    //get the data locations
    getFilesLoc(source, fileLocNames);
    //reserving size of datastream
    for (auto it = fileLocNames.begin(); it != fileLocNames.end(); it++) {
        datastreams.reserve(getDataNum(*it));
    }
    //inputing the actual datastreams
    for (auto it = fileLocNames.begin(); it != fileLocNames.end(); it++) {
        getDataFilesEntry(*it, datastreams);
    }
    return;
}

//gets number of files inside fileLoc - for initializing purposes
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
    return numEntry-2; //removes . and .. files
}

//actual initializationand input of elements of the datastream from fileLoc
static void getDataFilesEntry(const std::wstring& fileLoc, std::vector<std::ifstream>& datastream) {
    int removeDots = 0;
    WIN32_FIND_DATA data;
    HANDLE hFind;
    if ((hFind = FindFirstFile(fileLoc.c_str(), &data)) != INVALID_HANDLE_VALUE) {
        do {
            //removes . and .. files
            if (removeDots<2) {
                removeDots++;
                continue;
            }
            std::wstring fileDestination(fileLoc);
            fileDestination.pop_back(); //removes \*
            datastream.emplace_back(std::ifstream(fileDestination.append(data.cFileName)));
        } while (FindNextFile(hFind, &data) != 0);
        FindClose(hFind);
    }
}

//fileLoc, filenames : returns filenames of the files inside fileLoc inside filenames
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
                //removes . and .. files
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

//buffer : gets current directory and returns it in buffer
static bool getCurrentLoc(const LPTSTR& buffer) {
    DWORD dwRet;
    dwRet = GetCurrentDirectory(BUFFSIZE, buffer);

    if (dwRet == 0 || dwRet > BUFFSIZE) {
        return false;
    }

    return true;
}
