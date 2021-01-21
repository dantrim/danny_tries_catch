#pragma once
#include "catch2/catch.hpp"

//std/stl
#include <vector>

struct TestData0 {
    TestData0() {
        data = {4,3,2,1,0};
    }
    std::vector<int> data;
};

TEST_CASE_METHOD(TestData0, "Test contents of data0", "[fixtures]") {
    CAPTURE(data);
    REQUIRE(data.size() == 5);
    REQUIRE(data.at(0) == 4);
    REQUIRE(data.at(1) == 3);
    REQUIRE(data.at(2) == 2);
    REQUIRE(data.at(3) == 1);
    REQUIRE(data.at(4) == 0);
}