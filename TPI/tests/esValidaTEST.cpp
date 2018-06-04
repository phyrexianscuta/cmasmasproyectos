#include "../ejercicios.h"
#include "gtest/gtest.h"

using namespace std;


TEST(esValidaTEST, valida){
    senial s = {0};
    EXPECT_TRUE(esValida(s));
}
