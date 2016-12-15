#include "catch.hpp"
#include <stack.hpp>

SCENARIO("If stack is empty when popping") {
    GIVEN("Empty stack")
    {
        stack<int> st1;
        WHEN("popping")
        {
            THEN("do")
            {
                REQUIRE(st1.count()==0);
               // REQUIRE_THROWS_AS(st1.pop(), std::underflow_error);
            }
        }
    }
}
