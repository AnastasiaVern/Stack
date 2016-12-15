#include "catch.hpp"
#include <stack.hpp>

SCENARIO("Top() returns top element")
{
    GIVEN("If stack is completely empty")
    {
        stack<int> st1;
        WHEN("st1.top()")
        {
            THEN("underflow_error")
            {
                REQUIRE_THROWS_AS(st1.top(), std::underflow_error);
            }
        }
    }
}
