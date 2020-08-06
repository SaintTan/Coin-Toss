#include "Data.h"

//starting datastream
Data::Data::Data(const std::wstring& source):sd_datastream(){
	getDataFiles(source, sd_datastream);
};

//get names of files
void Data::Data::getDataNames(const std::wstring& source, std::vector<std::wstring>& filenames) {
	getDataFilesName(source, filenames);
}

//reading in lines to update data
void Data::Data::getData(unsigned int i, std::string& string) {
	std::getline(sd_datastream[i], string);
	//check for any errors
	if (sd_datastream[i].bad()) {
		string = "";
	}
	else if (sd_datastream[i].eof()) {
		string = "";
	}
	return;
}


