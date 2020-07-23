#include <string>
#include <iostream>
#include <fstream>
#include <windows.h>

#define BUFFSIZE MAX_PATH

static void getFiles(const wchar_t& filename, const wchar_t& relative_path) {
	wchar_t currentDir[BUFFSIZE];
	DWORD dirRet;
	dirRet = GetCurrentDirectory(BUFFSIZE, currentDir);
	if (dirRet > BUFFSIZE || dirRet == 0) {
		return;
	}
	else {
		wchar_t savefileDir[BUFFSIZE];
		wcscpy_s(savefileDir, currentDir);
		wcscat_s(savefileDir, &filename);

		wcscat_s(currentDir, &relative_path);
		wchar_t fullFiles[2] = { '\\', '*' };
		wcscat_s(currentDir, fullFiles);


		std::wcout << currentDir << "\n" << std::endl;
		

		/*std::ofstream outfile;
		outfile.open(filename);

		WIN32_FIND_DATA data;
		HANDLE hFind;*/
		delete[] savefileDir;
	}
	delete[] currentDir;
}