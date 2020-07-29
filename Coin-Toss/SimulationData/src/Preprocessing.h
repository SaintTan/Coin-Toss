#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <windows.h>

#define BUFFSIZE MAX_PATH

static void getFilesLoc(std::vector<std::wstring>& const);
static int readInLocFilesNum(const std::wstring&);
static void readInLocFilesEntry(const std::wstring&, std::vector<std::wstring>&);
void getDataFiles(std::vector<std::ifstream>&);
static int getDataNum(const std::wstring&);
static void getDataFilesEntry(const std::wstring&, std::vector<std::ifstream>&);
static bool getCurrentLoc(const LPTSTR&);