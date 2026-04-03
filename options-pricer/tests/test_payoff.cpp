#include <gtest/gtest.h>
#include "payoff.h"

// payoff function tests
TEST(Payoff, CallInTheMoney) {
    EXPECT_DOUBLE_EQ(payoff(OptionType::Call, 110.0, 100.0), 10.0);
}

TEST(Payoff, CallOutOfTheMoney) {
    EXPECT_DOUBLE_EQ(payoff(OptionType::Call, 90.0, 100.0), 0.0);
}

TEST(Payoff, PutInTheMoney) {
    EXPECT_DOUBLE_EQ(payoff(OptionType::Put, 90.0, 100.0), 10.0);
}

TEST(Payoff, PutOutOfTheMoney) {
    EXPECT_DOUBLE_EQ(payoff(OptionType::Put, 110.0, 100.0), 0.0);
}

// norm_cdf tests
TEST(NormCdf, AtZero) {
    EXPECT_NEAR(norm_cdf(0.0), 0.5, 1e-10);
}

TEST(NormCdf, LargePositive) {
    EXPECT_NEAR(norm_cdf(10.0), 1.0, 1e-6);
}

TEST(NormCdf, LargeNegative) {
    EXPECT_NEAR(norm_cdf(-10.0), 0.0, 1e-6);
}

// norm_pdf tests
TEST(NormPdf, AtZero) {
    EXPECT_NEAR(norm_pdf(0.0), 0.3989, 0.001);
}

TEST(NormPdf, IsSymmetric) {
    EXPECT_NEAR(norm_pdf(1.0), norm_pdf(-1.0), 1e-10);
}