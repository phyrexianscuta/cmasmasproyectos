#include "../ejercicios.h"
#include "gtest/gtest.h"

using namespace std;

TEST(medianaEnteraTEST, cantidadPar){
    senial s = {8, 4, 6, 9, 2, 1};
    int latencia;
    int res = medianaEntera(s, latencia);

    EXPECT_EQ(latencia, 1);
    EXPECT_EQ(res, 4);
}
