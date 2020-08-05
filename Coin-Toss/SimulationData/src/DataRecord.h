#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <windows.h>

#define BUFFSIZE MAX_PATH

static bool getCurrentLoc(const LPTSTR& buffer);