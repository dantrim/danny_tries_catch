#pragma once
#include "catch2/catch.hpp"

//std/stl
#include <vector>
#include <sstream>

std::string vec2string(const std::vector<int>& vec) {
    std::stringstream s;
    s << "{";
    for(const auto& v : vec) {
        s << " " << v;
    }
    s << " }";
    return s.str();
}

class MyGenerator : public Catch::Generators::IGenerator<int> {
    public :
        MyGenerator() {
            _index = -1;
            _v = {1, 2, 3};
            static_cast<void>(next());
        }
        bool next() override {
            _index++;
            if(_index >= _v.size()) { 
                return false;
            }
            current_number = _v.at(_index);
            return true;
        }

        int const& get() const override;

    private :
        int current_number;
        size_t _index;
        std::vector<int> _v;
};

int const& MyGenerator::get() const {
    return current_number;
}

// provide a nice interface to the custom generator
Catch::Generators::GeneratorWrapper<int> my_generator() {
    return Catch::Generators::GeneratorWrapper<int>(std::unique_ptr<Catch::Generators::IGenerator<int>>(new MyGenerator()));
}

TEST_CASE("Illustrating basic GENERATE functionality with integers", "[generators] [int]") {
    auto x = GENERATE(1, 2);
    SECTION("SECTION A") {
        INFO("SECTION A x = " << x);
        SUCCEED();
    }

    auto y = GENERATE(1, 2);
    SECTION("SECTION B") {
        INFO("SECTION B x = " << x << ", y = " << y);
        SUCCEED();
    }
}

TEST_CASE("Illustrating basic GENERATE functionality with vectors", "[generators] [vector]") {
    auto vi = GENERATE(std::vector<int>{1}, std::vector<int>{2,2});
    SECTION("SECTION A") {
        INFO("SECTION A vi = " << vec2string(vi));
        SUCCEED();
    }
    auto vj = GENERATE(std::vector<int>{1}, std::vector<int>{2,2});
    SECTION("SECTION B") {
        INFO("SECTION B vi = " << vec2string(vi) << ", vj = " << vec2string(vj));
        SUCCEED();
    }
}

TEST_CASE("Illustrating custom generator", "[generators] [custom]") {
    auto i = GENERATE(my_generator());
    SECTION("SECTION A") {
        INFO("SECTION A i = " << i);
        SUCCEED();
    }
    auto j = GENERATE(my_generator());
    SECTION("SECTION B") {
        INFO("SECTION B i = " << i << ", j = " << j);
        SUCCEED();
    }
}