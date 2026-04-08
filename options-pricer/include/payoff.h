#pragma once
#include <algorithm>
#include "option.h"

inline double payoff(OptionType type, double spot, double strike) {

    if (type == OptionType::Call)
        return std::max(spot - strike, 0.0);
    else
        return std::max(strike - spot, 0.0);
}