# Options Pricing Library

C++17 library for computing and comparing European option prices under Black-Scholes, Monte Carlo, and Binomial Tree models.

## Project Structure

- `options-pricer/` — main project directory
  - `include/` — headers
  - `src/` — implementations
  - `tests/` — Google Test unit tests
  - `configs/` — JSON config files

## Build

```bash
# From options-pricer/
cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=[vcpkg-root]/scripts/buildsystems/vcpkg.cmake
cmake --build build
```

## Test

```bash
cmake --build build --target test
# or
cd build && ctest --output-on-failure
```

## Dependencies (vcpkg)

- nlohmann-json
- gtest (Google Test)
- CLI11

## Conventions

- C++17 standard
- All pricing models implement the `PricingModel` interface (virtual `price()` and `name()`)
- Core types: `Option`, `MarketData` (in `option.h`, `market_data.h`)
- Put-call parity is the primary cross-validation check across models
- Tests use known analytical values from Black-Scholes as ground truth

## Phases

- Phase 0: Project setup, CMake, core types, PricingModel interface
- Phase 1: Payoff functions + Black-Scholes
- Phase 2: Monte Carlo simulation
- Phase 3: Binomial Tree
- Phase 4: Greeks (analytical + numerical)
- Phase 5: Benchmarking + CLI
