#include <iostream>
#include <string>
#include <CLI/CLI.hpp>
#include "black_scholes.h"

int main(int argc, char* argv[]) {
    // --- declare variables that will hold your inputs ---
    double spot, strike, maturity, vol, rate;
    std::string type_str;

    // --- CLI11 reads your command-line flags into those variables ---
    CLI::App app{"Options Pricer"};
    app.add_option("--spot",     spot,     "Current stock price")->required();
    app.add_option("--strike",   strike,   "Strike price")->required();
    app.add_option("--maturity", maturity, "Time to maturity in years")->required();
    app.add_option("--vol",      vol,      "Volatility (e.g. 0.2 for 20%)")->required();
    app.add_option("--rate",     rate,     "Risk-free rate (e.g. 0.05 for 5%)")->required();
    app.add_option("--type",     type_str, "Option type: call or put")->required();
    CLI11_PARSE(app, argc, argv);

    // --- build the structs your pricing model expects ---
    OptionType type = (type_str == "call") ? OptionType::Call : OptionType::Put;
    Option option(strike, maturity, type);
    MarketData market(spot, rate, vol);

    // --- price it ---
    BlackScholesModel bs;
    double price = bs.price(option, market);

    // --- print the result ---
    std::cout << "\nOption type : " << type_str
              << "\nSpot        : " << spot
              << "\nStrike      : " << strike
              << "\nMaturity    : " << maturity << " years"
              << "\nVolatility  : " << vol * 100 << "%"
              << "\nRate        : " << rate * 100 << "%"
              << "\n--------------------------"
              << "\nPrice       : " << price << "\n\n";

    return 0;
}