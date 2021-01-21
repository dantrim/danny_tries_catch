#pragma once
#include "catch2/catch.hpp"

std::uint64_t Fibonacci(std::uint64_t number) {
    return number < 2 ? 1 : Fibonacci(number - 1) + Fibonacci(number - 2);
}

TEST_CASE("Fibonacci", "[benchmark]") {
    CHECK(Fibonacci(0) == 1);
    // some more asserts..
    CHECK(Fibonacci(5) == 8);
    // some more asserts..

    // now let's benchmark:
    BENCHMARK("[benchmark][20]") {
        return Fibonacci(20);
    };

    BENCHMARK("[benchmark][25]") {
        return Fibonacci(25);
    };

    BENCHMARK("[benchmark][30]") {
        return Fibonacci(30);
    };

    BENCHMARK("[benchmark][35]") {
        return Fibonacci(35);
    };
}