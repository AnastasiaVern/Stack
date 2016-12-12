#include "catch.hpp"
#include <stack.hpp>

SCENARIO("If there's no elements in the stack")
{
    GIVEN("Empty stack")
    {
        stack<int> st1;
        WHEN("st1.empty()")
        {
            THEN("return true")
            {
                REQUIRE(st1.empty() == true);
            }
        }
    }

    GIVEN("If stack is full")
    {
        stack<int> st1;
        st1.push(10);
        st1.push(20);
        st1.push(30);
        WHEN("st1.empty()")
        {
            THEN("return false")
            {
                REQUIRE(st1.empty() == false);
            }
        }
    }
}
