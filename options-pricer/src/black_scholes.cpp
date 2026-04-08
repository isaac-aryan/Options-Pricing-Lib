#include "black_scholes.h"
#include "math_utils.h"
#include "payoff.h"
#include <cmath>

std::string BlackScholesModel::name() const {
    return "Black-Scholes";
}

double BlackScholesModel::price(const Option& option, const MarketData& market) const {
    double S = market.spot;
    double K = option.K;
    double T = option.T;
    double r = market.r;
    double sigma = market.sigma;

    double d1 = (std::log(S / K) + (r + 0.5 * sigma * sigma) * T)
                / (sigma * std::sqrt(T));
    double d2 = d1 - sigma * std::sqrt(T);

    if (option.type == OptionType::Call)
        return S * norm_cdf(d1) - K * std::exp(-r * T) * norm_cdf(d2);
    else
        return K * std::exp(-r * T) * norm_cdf(-d2) - S * norm_cdf(-d1);
}