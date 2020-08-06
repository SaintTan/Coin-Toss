#include "Data.h"

Data::Data::Data(const std::wstring& source):sd_datastream(){
	getDataFiles(source, sd_datastream);
};

void Data::Data::getDataNames(const std::wstring& source, std::vector<std::wstring>& filenames) {
	getDataFilesName(source, filenames);
}

void Data::Data::getData(unsigned int i, std::string& string) {
	std::getline(sd_datastream[i], string);
	if (sd_datastream[i].bad()) {
		string = "";
	}
	else if (sd_datastream[i].eof()) {
		string = "";
	}
	else {
		return;
	}
}


