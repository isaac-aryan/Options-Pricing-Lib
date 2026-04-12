#include "monte_carlo.h"
#include "payoff.h"
#include <random>
#include <cmath>

std::string MonteCarloModel::name() const {
    return "Monte Carlo";
}

double MonteCarloModel::price(const Option& option, const MarketData& market) const {
    double S = market.spot;
    double K = option.K;
    double T = option.T;
    double r = market.r;
    double sigma = market.sigma;

    std::mt19937 rng(seed);
    std::normal_distribution<double> distribution(0.0, 1);

    double drift = r - 0.5 * sigma * sigma;
    double diffusion = sigma * std::sqrt(T);

    double sum_payoff = 0.0;
    for (std::size_t i = 0; i < num_simulations; ++i) {
        double Z = distribution(rng);
        double S_T = S * std::exp(drift * T + diffusion * Z);
        sum_payoff += payoff(option.type, S_T, K);
    }
    double mean_payoff = sum_payoff / static_cast<double>(num_simulations);

    return std::exp(-r * T) * mean_payoff;
}