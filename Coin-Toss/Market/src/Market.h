#pragma once
#include "Stock.h"
#include <string>
#include <array>

namespace Market {
	template <size_t size, size_t size_s>
	class Market {
	private:
		std::string marketID;
		std::array<Stock::Stock<size_s>, size> stocks;
	public:
		Market();
		void updateStock();
		~Market();
	protected:
	};
}

