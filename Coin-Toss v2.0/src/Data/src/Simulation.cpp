#include "Simulation.h"

Data::Simulation::Simulation(const std::string& fileLoc, const std::string& fileName) : readFile(fileLoc + fileName) {};
Data::Simulation::Simulation(const std::string& file) : readFile(file) {};

void Data::Simulation::readData(std::string& temp){
	if (readFile.eof()) {
		readFile.close();
	}
	if (readFile.is_open()) {
		std::getline(readFile, temp);
	}
	temp = "";
}
