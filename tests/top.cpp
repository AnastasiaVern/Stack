#include "catch.hpp"
#include <stack.hpp>

SCENARIO("Top() returns top element")
{
    GIVEN("Stack")
    {
        stack<int> st1;
        st1.push(1);
        st1.push(2);
        st1.push(3);
        WHEN("st1.top()")
        {
            THEN("st1.top() must return 3")
            {
                REQUIRE(st1.top() == 3);
            }
        }
    }
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
