#pragma once
#include <iostream>
#include <vector>

namespace Stock {
	struct StockQue {
	private:
	public:
		std::vector<float> mq_topPrice_B, mq_topPrice_S; //vector for the prices 
		std::vector<unsigned int> mq_topVol_B, mq_topVol_S; //vector for the volumes
		unsigned int mq_size;//size of stockque
		StockQue(unsigned int size): mq_size(size) {
			mq_topPrice_B.reserve(size);
			mq_topPrice_S.reserve(size);
			mq_topVol_B.reserve(size);
			mq_topVol_S.reserve(size);
		}
		void print() {
			std::cout << "Prices" << std::endl;
			std::cout << mq_topPrice_B[0] << ", " << mq_topPrice_B[1] << ", " << mq_topPrice_B[2] << ", " << std::endl;
			std::cout << mq_topPrice_S[0] << ", " << mq_topPrice_S[1] << ", " << mq_topPrice_S[2] << ", " << std::endl;
			std::cout << "Volume" << std::endl;
			std::cout << mq_topVol_B[0] << ", " << mq_topVol_B[1] << ", " << mq_topVol_B[2] << ", " << std::endl;
			std::cout << mq_topVol_S[0] << ", " << mq_topVol_S[1] << ", " << mq_topVol_S[2] << ", " << std::endl;
		}
	protected:
	};
}
