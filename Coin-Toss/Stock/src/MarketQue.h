#pragma once
#include <vector>

namespace Stock{
	template<size_t size>
	struct MarketQue {
	private:
	public:
		std::vector<float> mq_topPrice_B, mq_topPrice_S;
		std::vector<unsigned int> mq_topVol_B, mq_topVol_S;
		MarketQue() {
			mq_topPrice_B.reserve(size);
			mq_topPrice_S.reserve(size);
			mq_topVol_B.reserve(size);
			mq_topVol_S.reserve(size);
		}
	protected:
	};
}
