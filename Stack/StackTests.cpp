#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "Stack.h"

Stack<2> MakeStack() {
    return {};
}

TEST_CASE("A new stack should") {
    auto s = MakeStack();

    SECTION("be empty") {
        REQUIRE(s.empty());
    }

    SECTION("throw an underflow exception when popped empty") {
        REQUIRE_THROWS_AS(s.pop(), Stack<2>::Underflow);
    }
}

TEST_CASE("A stack containing an element X should") {
    auto s = MakeStack();
    s.push(42);

    SECTION("not be empty") {
        REQUIRE(!s.empty());
    }

    SECTION("pop back X") {
        REQUIRE(s.pop() == 42);
    }

    SECTION("be empty again after X has been popped") {
        s.pop();
        REQUIRE(s.empty());
    }
}

TEST_CASE("A stack containing elements X and Y should") {
    auto s = MakeStack();
    s.push(1);
    s.push(2);

    SECTION("be empty again after popping all elements") {
        s.pop();
        s.pop();
        REQUIRE(s.empty());
    }

    SECTION("pop back Y and then X") {
        REQUIRE(s.pop() == 2);
        REQUIRE(s.pop() == 1);
    }
}

TEST_CASE("A stack that has reached its capacity should throw an overflow exception when an element is pushed") {
    Stack<2> s;
    s.push(1);
    s.push(2);
    REQUIRE_THROWS_AS(s.push(3), Stack<2>::Overflow);
}

TEST_CASE("A stack's capacity can be configured through its template parameter") {
    Stack<3> s;
    s.push(1);
    s.push(2);
    s.push(3);
}