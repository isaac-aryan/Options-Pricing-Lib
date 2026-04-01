#pragma once
#include <string>
#include "option.h"
#include "market_data.h"    

class PricingModel {
public:
    virtual double price(const Option& option, const MarketData& marketData) const = 0;
    virtual std::string name() const = 0;
    virtual ~PricingModel() {}
};  

