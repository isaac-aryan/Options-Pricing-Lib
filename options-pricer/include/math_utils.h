#pragma once
#define _USE_MATH_DEFINES
#include <cmath>

inline double norm_cdf(double x) {
    return 0.5 * std::erfc(-x / std::sqrt(2.0));
}

inline double norm_pdf(double x) {
    return (1.0 / std::sqrt(2.0 * M_PI)) * std::exp(-0.5 * x * x);
}
