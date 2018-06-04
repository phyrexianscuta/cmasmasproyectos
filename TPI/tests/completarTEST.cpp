#include "../ejercicios.h"
#include "gtest/gtest.h"

using namespace std;

void testeo (vector<int> &s, vector<int> &res) {
    ASSERT_EQ(s.size(), res.size());
    for (int i = 0; i < s.size(); ++i) {
        EXPECT_EQ(s[i], res[i]);
    }
}

TEST(completarTEST, huecoSimple){
    vector<int> missings = {2};

    senial s = {33,25,0,3,1};
    senial res = {33,25,14,3,1};

    completar(s,missings);

    testeo (s,res);
}
