#include "../ejercicios.h"
#include "gtest/gtest.h"

using namespace std;

void testeo (promedios &promediosRes, promedios &promedio, ventanas &ventanasRes, ventanas &ventana){

    ASSERT_EQ(ventanasRes.size(), ventana.size());
    ASSERT_EQ(promediosRes.size(), promedio.size());

    vector< tuple<int,int,float> > test;
    vector< tuple<int,int,float> > res;
    for (int i = 0; i < ventanasRes.size(); ++i) {
        tuple<int,int,float> elem = make_tuple(get<0>(ventana[i]), get<1>(ventana[i]), promedio[i]);
        tuple<int,int,float> elemRes = make_tuple(get<0>(ventanasRes[i]), get<1>(ventanasRes[i]), promediosRes[i]);
        test.push_back(elem);
        res.push_back(elemRes);
    }
    sort(test.begin(),test.end());
    sort(res.begin(),res.end());

    for (int i = 0; i < ventanasRes.size(); ++i) {
        EXPECT_EQ(get<0>(test[i]), get<0>(res[i]));
        EXPECT_EQ(get<1>(test[i]), get<1>(res[i]));
        EXPECT_NEAR(get<2>(test[i]), get<2>(res[i]), 0.01);
    }
}

TEST(slidingWindowsTEST, tamaniosOrdenados){
    vector<int> tamanios = {2,3};
    senial s = {33,25,-1,3,1,2};

    ventanas ventanasRes = {make_tuple(0,1),make_tuple(2,3),make_tuple(4,5),make_tuple(0,2),make_tuple(3,5)};
    promedios promediosRes = {29,1,1.5,19,2};

    tuple<promedios,ventanas > res = slidingWindows(s, tamanios);

    testeo (promediosRes, get<0>(res), ventanasRes, get<1>(res));
}

TEST(slidingWindowsTEST, tamaniosDesordenados){
    vector<int> tamanios = {3,2};
    senial s = {33,25,-1,3,1,2};

    ventanas ventanasRes = {make_tuple(0,2),make_tuple(3,5),make_tuple(0,1),make_tuple(2,3),make_tuple(4,5)};
    promedios promediosRes = {19,2,29,1,1.5};

    tuple<promedios,ventanas > res = slidingWindows(s, tamanios);

    testeo (promediosRes, get<0>(res), ventanasRes, get<1>(res));
}

TEST(slidingWindowsTEST, respuestaDesordenada){
    vector<int> tamanios = {2,3};
    senial s = {33,25,-1,3,1,2};

    ventanas ventanasRes = {make_tuple(4,5),make_tuple(3,5),make_tuple(0,1),make_tuple(0,2),make_tuple(2,3),};
    promedios promediosRes = {1.5,2,29,19,1};

    tuple<promedios,ventanas > res = slidingWindows(s, tamanios);

    testeo (promediosRes, get<0>(res), ventanasRes, get<1>(res));
}

TEST(slidingWindowsTEST, listaExtendida1){
    vector<int> tamanios = {2,3};
    senial s = {33,25,-1,3,1};

    ventanas ventanasRes = {make_tuple(0,1),make_tuple(2,3),make_tuple(4,5),make_tuple(0,2),make_tuple(3,5)};
    promedios promediosRes = {29,1,1,19,1.66};

    tuple<promedios,ventanas > res = slidingWindows(s, tamanios);

    testeo (promediosRes, get<0>(res), ventanasRes, get<1>(res));
}

TEST(slidingWindowsTEST, listaExtendida2){
    vector<int> tamanios = {2,3};
    senial s = {33,25,-1,3};

    ventanas ventanasRes = {make_tuple(0,1),make_tuple(2,3),make_tuple(0,2),make_tuple(3,5)};
    promedios promediosRes = {29,1,19,3};

    tuple<promedios,ventanas > res = slidingWindows(s, tamanios);

    testeo (promediosRes, get<0>(res), ventanasRes, get<1>(res));
}
