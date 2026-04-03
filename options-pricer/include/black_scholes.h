#pragma once
#include "pricing_model.h"

class BlackScholesModel : public PricingModel {
public:
    double price(const Option& option, const MarketData& market) const override;
    std::string name() const override;
};