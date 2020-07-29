#include "src/Preprocessing.h"

int main() {
	std::vector<std::ifstream> data;
	getDataFiles(data);
	std::string actualdata;
	std::cout << data.size() << std::endl;
	while (std::getline(data[3], actualdata)) {
		std::cout << actualdata << std::endl;
	}
}