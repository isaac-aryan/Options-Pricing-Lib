cmake_minimum_required(VERSION 3.20)
project(options-pricer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Dependencies
find_package(nlohmann_json CONFIG REQUIRED)
find_package(GTest CONFIG REQUIRED)
find_package(CLI11 CONFIG REQUIRED)

# Library (all pricing model sources)
add_library(pricer_lib
    src/black_scholes.cpp
    src/monte_carlo.cpp
    src/binomial_tree.cpp
    src/greeks.cpp
    src/benchmark.cpp
)
target_include_directories(pricer_lib PUBLIC include)
target_link_libraries(pricer_lib PUBLIC nlohmann_json::nlohmann_json)

# Main executable
add_executable(options-pricer src/main.cpp)
target_link_libraries(options-pricer PRIVATE pricer_lib CLI11::CLI11)

# Tests
enable_testing()

add_executable(tests
    tests/test_payoff.cpp
    tests/test_black_scholes.cpp
    tests/test_monte_carlo.cpp
    tests/test_binomial_tree.cpp
    tests/test_greeks.cpp
)
target_link_libraries(tests PRIVATE pricer_lib GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(tests)
