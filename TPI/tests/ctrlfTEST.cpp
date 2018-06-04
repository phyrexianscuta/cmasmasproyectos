#include "../ejercicios.h"
#include "gtest/gtest.h"

using namespace std;

void testeo (vector<int> indices, vector<int> indicesRes){
    ASSERT_EQ(indices.size(), indicesRes.size());
    for (int i = 0; i < indices.size(); ++i) {
        EXPECT_EQ(indices[i],indicesRes[i]);
    }
}

TEST(ctrlfTEST, resultadoVacio){
    senial s = {124, -25, -250, 17, 5};
    vector<int> indices= ctrlf(s, 0);
    vector<int> indicesRes;

    testeo(indices, indicesRes);
}
