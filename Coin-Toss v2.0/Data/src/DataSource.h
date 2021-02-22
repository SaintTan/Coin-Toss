#pragma once
#include <string>

namespace Data {
	class DataSource {
	public: 
		virtual void readData(std::string&) = 0;
	};
}

