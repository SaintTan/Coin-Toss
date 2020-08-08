#pragma once

#include "Preprocess.h"
#include <string>
#include <vector>

namespace Data{
	class Data {
	private:
		std::vector<std::ifstream> sd_datastream; //for storing datastream
	public:
	protected:
		Data(const std::wstring&);
		static void getDataNames(const std::wstring&, std::vector<std::wstring>&); //source, filenames: returns a vector of filenames 
		void getData(unsigned int, std::string&); //datastreamNum, string: returns a string from reading an element of the stored datastream

	};
}


