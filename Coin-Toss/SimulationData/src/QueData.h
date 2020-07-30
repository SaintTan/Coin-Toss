#pragma once
#include "Data.h"
#include <string>
#include <fstream>
#include <vector>

namespace Data {
	class QueData : public Data {
	private:
		static std::wstring location;
	public:
		QueData();
		void updateData(unsigned int i, Stock::Stock& const);
		~QueData();
	protected:
	};
}


