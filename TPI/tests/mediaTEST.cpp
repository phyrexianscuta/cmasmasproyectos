#include "../ejercicios.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mediaTEST, resultadoEntero){
    senial s = {124, -25, -250, 17};
    EXPECT_NEAR(media(s),104,0.001);
}
