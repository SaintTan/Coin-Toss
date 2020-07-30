#pragma once

#include "Stock.h"
#include "Preprocessing.h"
#include <string>
#include <vector>

namespace Data{
	class Data {
	private:
		std::vector<std::ifstream> sd_datastream;
	public:
	protected:
		Data(const std::wstring&);
		void getData(unsigned int, std::string& const);
	};
}


