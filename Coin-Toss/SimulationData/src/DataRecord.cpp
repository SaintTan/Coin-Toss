#include "DataRecord.h"


void write_toFile(std::wstring& source, const std::string data ) {
    LPTSTR buffer = new TCHAR[BUFFSIZE];
    getCurrentLoc(buffer);
    std::wstring datasource(buffer);
    datasource.append(L"\\record\\").append(source);
    std::ofstream file(datasource);
    file << data << std::endl;
    file.close();
}

static bool getCurrentLoc(const LPTSTR& buffer) {
    DWORD dwRet;
    dwRet = GetCurrentDirectory(BUFFSIZE, buffer);

    if (dwRet == 0 || dwRet > BUFFSIZE) {
        return false;
    }

    return true;
}