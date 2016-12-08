
#include "catch.hpp"
#include <stack.hpp>

SCENARIO("Incremented number of elements after pushing one to the stack")
{
    GIVEN("stack")
    {
        stack<int> st1;
        st1.push(10);
        st1.push(4);
        auto count = st.count();
        WHEN("pushing")
        {
            st.push(43);
            THEN("Number of elements must be incremented by 1")
            {
                REQUIRE(st1.count() == count + 1);
            }
        }
    }
}
