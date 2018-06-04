#include "../ejercicios.h"
#include "gtest/gtest.h"

using namespace std;

TEST(distanciaEuclidianaTEST, todosNegativos){
    senial p = {-67, -47, -361};
    senial q = {-58, -184, -214};
    EXPECT_NEAR(distanciaEuclidiana(p,q), 201.144,0.001);
}
