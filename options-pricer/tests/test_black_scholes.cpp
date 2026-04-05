#include <cmath>
#include <gtest/gtest.h>
#include "black_scholes.h"

TEST(BlackScholes, CallPrice) {
    Option option(100.0, 1.0, OptionType::Call);
    MarketData market(100.0, 0.05, 0.2);
    BlackScholesModel bs;
    EXPECT_NEAR(bs.price(option, market), 10.4506, 0.001);
}

TEST(BlackScholes, PutPrice) {
    Option option(100.0, 1.0, OptionType::Put);
    MarketData market(100.0, 0.05, 0.2);
    BlackScholesModel bs;
    EXPECT_NEAR(bs.price(option, market), 5.5735, 0.001);
}

TEST(BlackScholes, PutCallParity) {
    Option call(100.0, 1.0, OptionType::Call);
    Option put(100.0, 1.0, OptionType::Put);
    MarketData market(100.0, 0.05, 0.2);
    BlackScholesModel bs;

    double C = bs.price(call, market);
    double P = bs.price(put, market);
    double parity = market.spot - call.K * std::exp(-market.r * call.T);

    EXPECT_NEAR(C - P, parity, 0.001);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}