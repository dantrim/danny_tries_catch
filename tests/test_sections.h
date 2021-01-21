#pragma once
#include "catch2/catch.hpp"

#include <vector>

TEST_CASE("Testing Catch2 sections", "[sections]") {

    std::vector<int> v{1,2,3};

    SECTION("Add 1 element to the vector", "[sections] [add]") {
        REQUIRE(v.size() == 3);
        CAPTURE(v);
        v.push_back(4);
        REQUIRE(v.size() == 4);
        CAPTURE(v);
    }

    SECTION("Add 2 elements to the vector", "[sections] [add]") {
        REQUIRE(v.size() == 3);
        CAPTURE(v);
        v.push_back(4);
        v.push_back(5);
        REQUIRE(v.size() == 5);
        CAPTURE(v);
    }
}