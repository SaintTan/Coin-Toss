#pragma once

#include <array>
#include <string>

template <size_t size>

class Stock
{
private:
public:
	Stock(const std::string& stockID, const std::array<float, size>& topCurPrice, const std::array<int, size>& topCurVol);
protected:
};

