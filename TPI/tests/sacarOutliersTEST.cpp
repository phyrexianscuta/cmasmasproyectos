#include "../ejercicios.h"
#include "gtest/gtest.h"
#include "../auxiliares.h"

using namespace std;

void testeo (vector<int> &s, vector<int> &res, vector<int> &borrados, vector<int> &borradosRes) {
    ASSERT_EQ(s.size(), res.size());
    for (int i = 0; i < s.size(); ++i)
        EXPECT_EQ(s[i], res[i]);

    ASSERT_EQ(ordenado(borrados), ordenado(borradosRes));


}

TEST(sacarOutliersTEST, sacoUno){
    senial s = range(0, 20);
    senial res = s;
    res[20] = 0;

    vector<int> borradosRes = {20};
    vector<int> borrados = sacarOutliers(s);

    testeo (s,res, borrados, borradosRes);
}


TEST(sacarOutliersTEST, sacoVariosJuntos){
    senial s = range(0, 100);
    senial res = s;
    res[100] = 0;
    res[99] = 0;
    res[98] = 0;
    res[97] = 0;
    res[96] = 0;

    vector<int> borradosRes = {100, 99, 98, 97, 96};
    vector<int> borrados = sacarOutliers(s);

    testeo (s,res, borrados, borradosRes);
}
