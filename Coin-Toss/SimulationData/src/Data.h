#pragma once

#include "Stock.h"
#include "Preprocess.h"
#include <string>
#include <vector>

namespace Data{
	class Data {
	private:
		std::vector<std::ifstream> sd_datastream;
	public:
	protected:
		Data(const std::wstring&);
		void getDataNames(const std::wstring& source, std::vector<std::wstring>& filenames);
		void getData(unsigned int, std::string& const);

	};
}


