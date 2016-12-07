#include "catch.hpp"
#include <stack.hpp>

SCENARIO("If stack is empty")
{
    GIVEN("Stack is empty")
    {
        stack<int> st1;
     WHEN("counting elements in stack")
        {
            THEN("there's no elem")
            {
                REQUIRE(st1.count() == 0);
            }
        }
    }
}

SCENARIO("If stack is not empty")
{
    GIVEN("Stack is not empty")
    {
        stack<int> st1;
        st1.push(30);
        st1.push(25);

        WHEN("counting elements in stack")
        {
            THEN("!=0")
            {
                REQUIRE(st1.count() != 0);
            }
        }
    }
}
