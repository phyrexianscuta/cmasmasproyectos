#include "../ejercicios.h"
#include "gtest/gtest.h"

using namespace std;

void testeo (vector<int> cuentas, vector<float> limites, vector<int> cuentasRes, vector<float> limitesRes){
    ASSERT_EQ(cuentas.size(), cuentasRes.size());
    for (int i = 0; i < cuentas.size(); ++i) {
        EXPECT_EQ(cuentas[i],cuentasRes[i]);
    }

    ASSERT_EQ(limites.size(), limitesRes.size());
    for (int i = 0; i < limites.size(); ++i) {
        EXPECT_NEAR(limites[i],limitesRes[i],0.001);
    }
}

TEST(histogramaTEST, testEnunciado){
    senial s = {33,24,24,1,62,88,94,79,25,24};
    int bins = 4;
    vector<int> cuentas;
    vector<float> limites;

    vector<int> cuentasRes = {4,2,1,3};
    vector<float> limitesRes= {1.00,24.25,47.50,70.75,94.00};

    std::tie (cuentas, limites) = histograma(s, bins);
    testeo (cuentas, limites, cuentasRes, limitesRes);
}
