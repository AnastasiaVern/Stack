#include "catch.hpp"
#include <stack.hpp>

SCENARIO("Decremented number of elements after popping one from the stack")
{
    GIVEN("stack")
    {
        stack<int> st1;
        st1.push(23);
        st1.push(45);
        auto count = st1.count();
        WHEN("popping")
        {
            st1.pop();
            THEN("Number of elements must be decremented by one")
            {
                REQUIRE(st1.count() == count - 1);
            }
        }
    }
}
SCENARIO("If stack is empty") {
    GIVEN("Empty stack")
    {
        stack<int> st1;
        WHEN("popping")
        {
            THEN("throw exception")
            {
                REQUIRE_THROWS_AS(st1.pop(), std::underflow_error);
            }
        }
    }
}
