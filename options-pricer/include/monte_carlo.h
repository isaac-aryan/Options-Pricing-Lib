#pragma once
#include <cstddef>
#include "pricing_model.h"

class MonteCarloModel : public PricingModel {
    std::size_t num_simulations;
    unsigned int seed;
public:
    MonteCarloModel(std::size_t num_simulations = 100000, unsigned int seed = 42) : num_simulations(num_simulations), seed(seed) {}
    double price(const Option& option, const MarketData& market) const override;
    std::string name() const override;
};
