#pragma once
#include <algorithm>
#include "option.h"

inline double payoff(OptionType type, double spot, double strike) {
    
    if (type == OptionType::Call)
        return std::max(spot - strike, 0.0);
    else
        return std::max(strike - spot, 0.0);
}

inline double norm_cdf(double x) {
    return 0.5 * std::erfc(-x / std::sqrt(2.0));
}

inline double norm_pdf(double x) {
    return (1.0 / std::sqrt(2.0 * M_PI)) * std::exp(-0.5 * x * x);
}