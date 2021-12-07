#include <iostream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>

#include "..\..\profile.h"
#include "..\..\test_runner.h"
#include "MyStock.h"

void Test_0() {
    int expected = 0;
    int tested = 0;
    ASSERT_EQUAL(tested, expected);
}

int main() {
    LOG_DURATION("Total Duration");

    // put it here
    MyStock st(5);
    st.RegPair("AA", "BB");
    st.RegPair("CC", "BB");
    st.RegPair("DD", "BB");
    st.RegPair("EE", "BB");
    st.UpdatePrice("AA", 1);
    st.UpdatePrice("BB", 2);
    st.UpdatePrice("CC", 3);
    st.UpdatePrice("DD", 4);
    st.UpdatePrice("EE", 6);
    st.UpdatePrice("BB", 7);
    st.UpdatePrice("BB", 20);

    TestRunner tr;

    {
        LOG_DURATION("Block Duration");
        RUN_TEST(tr, Test_0);
    }

    return 0;
}


