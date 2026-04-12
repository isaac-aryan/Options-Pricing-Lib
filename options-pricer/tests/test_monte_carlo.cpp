#include <cmath>
#include <gtest/gtest.h>
#include "monte_carlo.h"

TEST(MonteCarlo, CallPrice) {
    Option option(100.0, 1.0, OptionType::Call);
    MarketData market(100.0, 0.05, 0.2);
    MonteCarloModel mc;
    EXPECT_NEAR(mc.price(option, market), 10.4506, 0.5);
}

TEST(MonteCarlo, PutPrice) {
    Option option(100.0, 1.0, OptionType::Put);
    MarketData market(100.0, 0.05, 0.2);
    MonteCarloModel mc;
    EXPECT_NEAR(mc.price(option, market), 5.5735, 0.5);
}

TEST(MonteCarlo, PutCallParity) {
    Option call(100.0, 1.0, OptionType::Call);
    Option put(100.0, 1.0, OptionType::Put);
    MarketData market(100.0, 0.05, 0.2);
    MonteCarloModel mc;

    double C = mc.price(call, market);
    double P = mc.price(put, market);
    double parity = market.spot - call.K * std::exp(-market.r * call.T);

    EXPECT_NEAR(C - P, parity, 0.5);
}
