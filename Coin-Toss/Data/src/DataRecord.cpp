#include "DataRecord.h"

//appends data to the end of the source
void write_toFile(std::wstring& source, const std::string& data ) {
    //crete buffer
    LPTSTR buffer = new TCHAR[BUFFSIZE];
    getCurrentLoc(buffer);
    std::wstring datasource(buffer);
    datasource.append(L"\\record\\").append(source);
    std::ofstream file(datasource, std::ios_base::app);
    file << data << std::endl;
    file.close();
    delete[] buffer;
}

//get current file directory
static bool getCurrentLoc(const LPTSTR& buffer) {
    DWORD dwRet;
    dwRet = GetCurrentDirectory(BUFFSIZE, buffer);

    if (dwRet == 0 || dwRet > BUFFSIZE) {
        return false;
    }

    return true;
}