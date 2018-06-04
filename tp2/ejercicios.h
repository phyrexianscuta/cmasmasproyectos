#ifndef LECTURADECEREBROS_EJERCICIOS_H
#define LECTURADECEREBROS_EJERCICIOS_H
#include "definiciones.h"

using namespace std;

bool esValida(senial s);
float media(senial s);
vector<int> ctrlf(senial s, int x);
int maximo(senial s, int& latencia);
int medianaEntera(senial s, int& latencia);
tuple<vector<int>,vector<float> > histograma(senial s, int bins);
float distanciaEuclidiana(senial p, senial q);
tuple<float,vector<tuple<int,int> > > distanciaAcordeon(senial s, senial q);
tuple<promedios,ventanas > slidingWindows(senial s, vector<int> tamanios);
void completar(senial& s, vector<int> missings);
vector<int> sacarOutliers(senial& s);


#endif //LECTURADECEREBROS_EJERCICIOS_H
