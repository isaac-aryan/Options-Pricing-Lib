#pragma once 

enum class OptionType { Call, Put };

struct Option {
    double K;  // Strike price
    double T;  // Time to maturity
    OptionType type;

    Option(double K, double T, OptionType type)
        : K(K), T(T), type(type) {}
};

