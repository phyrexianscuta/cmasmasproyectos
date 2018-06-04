#include "../ejercicios.h"
#include "gtest/gtest.h"

using namespace std;



TEST(maximoTEST, todosPositivos){
    senial s = {78, 746, 156};
    int latencia;
    int max = maximo(s,latencia);
    EXPECT_EQ(max, 746);
    EXPECT_EQ(latencia, 1);
}
