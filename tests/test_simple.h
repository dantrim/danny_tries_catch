#pragma once
#include "catch2/catch.hpp"

#include <iostream>

unsigned int add1(unsigned int number) {
    return number + 1;
}

unsigned int add2(unsigned int number) {
    return number + 2;
}

TEST_CASE("Add one to an input number", "[simple] [add1]") {
    REQUIRE(add1(1) == 2);
    std::string my_string = "foobly doobly";
    int my_int = 42;
    CAPTURE(my_int, my_string);
    REQUIRE(add1(2) == 3);
    REQUIRE(add1(100) == 101);
}

TEST_CASE("Add two to an input number", "[simple] [add2]") {
    REQUIRE(add2(1) == 3);
    REQUIRE(add2(2) == 4);
    REQUIRE(add2(100) == 102);
}