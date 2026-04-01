#pragma once

struct MarketData {
    double spot; // Initial stock price
    double r;  // Risk-free rate
    double sigma; // Volatility

    MarketData(double spot, double r, double sigma)
        : spot(spot), r(r), sigma(sigma) {}
};

