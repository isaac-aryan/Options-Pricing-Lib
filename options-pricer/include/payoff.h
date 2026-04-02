#pragma once
#include "option.h"
#include <algorithm>

double inline payoff(const Option& option, double stock_price){
    if (option.type == OptionType::Call){
        return std::max(0.0, stock_price - option.K);
    } else {
        return std::max(0.0, option.K - stock_price);
    } 
}

