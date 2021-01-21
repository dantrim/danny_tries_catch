#pragma once
#include "catch2/catch.hpp"

#include "foo.h"

TEST_CASE("Test of libfoo", "[foo]") {
    REQUIRE(foo::add1(0) == 1);
    CHECK_NOFAIL(foo::add1(4) == 4);
    REQUIRE_FALSE(foo::add1(4) == 3);
}