#pragma once
#include <array>

namespace Stock{
	template<size_t size>
	struct MarketQue {
		std::array<float, size> s_topPrice_B, s_topPrice_S;
		std::array<unsigned int, size> s_topVol_B, s_topVol_S;
	};
}
