#include "Stock.h"
#include "SimulationData.h"
#include "MarketQue.h"
#include <string>
#include <array>
#include <vector>

int main() {
	std::string pathDir = "..\\..\\Coin-toss-data\\RHB\\data\\*";
	SimulationData::SimulationData mySim(pathDir);
}