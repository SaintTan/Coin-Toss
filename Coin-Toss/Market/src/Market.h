#pragma once
#include "Stock.h"
#include <string>
#include <array>

namespace Market {
	template <size_t size, size_t size_s, size_t size_cs>
	class Market {
	private:
		std::string marketID;
		std::array<Stock::Stock<size_s, size_cs>, size> stocks;
	public:
		Market();
		void updateStock();
		~Market();
	protected:
	};
}

