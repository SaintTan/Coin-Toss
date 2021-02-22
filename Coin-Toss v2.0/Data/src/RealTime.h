#pragma once
#include "DataSource.h"
#include <string>

namespace Data {
	class RealTime : public DataSource {
	private:
		std::string urlName;
	public:
		RealTime(const std::string& url, const std::string& pageName);
		RealTime(const std::string& fullurl);
		void readData(std::string& temp) override;
	};
}

