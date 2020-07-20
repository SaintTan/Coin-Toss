#pragma once
#include <string>

namespace DataCollect {
	class DataCollect {
	private:
		std::string dc_filename;
	public:
		DataCollect(std::string& filename);
		~DataCollect();
	protected:
	};

}

