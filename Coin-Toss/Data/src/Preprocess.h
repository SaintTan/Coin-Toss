#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <windows.h>

#define BUFFSIZE MAX_PATH

static void getFilesLoc(const std::wstring&, std::vector<std::wstring>&); //source, fileLocNames : looks for files in the current directory inside the folder "data" and returns the file directories inside fileLocNames
static int readInLocFilesNum(const std::wstring&); //fileLocName : reads how many entries are there inside fileLocName - for initializing purposes
static void readInLocFilesEntry(const std::wstring&, std::vector<std::wstring>&); //source, fileLocNames : reads in data and return it in fileLoc Names
void getDataFiles(const std::wstring&, std::vector<std::ifstream>&); //source, datastream : reads in from source and inputs it inside datastream, used to read multiple files
static int getDataNum(const std::wstring&); //fileLoc : gets number of files inside fileLoc - for initializing purposes
static void getDataFilesEntry(const std::wstring&, std::vector<std::ifstream>&); //fileLoc, datastream : actual initialization and input of elements of the datastream from fileLoc
void getDataFilesName(const std::wstring&, std::vector<std::wstring>&); //fileLoc, filenames : returns filenames of the files inside fileLoc inside fileNames
static bool getCurrentLoc(const LPTSTR&); //buffer : gets current directory and returns it in buffer