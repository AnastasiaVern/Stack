#include "catch.hpp"
#include <stack.hpp>

SCENARIO("Decremented number of elements after popping one from the stack")
{
    GIVEN("stack")
    {
        stack<int> st1;
        st1.push(2);
        st1.push(3);
        st1.push(4);
        st1.push(5);
        WHEN("popping")
        {
            st1.pop();
            THEN("Number of elements must be decremented by one")
            {
                REQUIRE(st1.count() == 3);
                REQUIRE(st1.top()==4);
            }
        }
    }
}
SCENARIO("If stack is empty when popping") {
    GIVEN("Empty stack")
    {
        stack<int> st1;
        WHEN("popping")
        {
            THEN("throw exception")
            {
                REQUIRE(st1.count()==0);
                REQUIRE_THROWS_AS(st1.pop(), std::underflow_error);
            }
        }
    }
}
