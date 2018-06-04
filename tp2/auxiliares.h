//
// Created by pbrusco on 22/05/18.
//
#include "definiciones.h"

using namespace std;

#ifndef LECTURADECEREBROS_AUXILIARES_H
#define LECTURADECEREBROS_AUXILIARES_H

// Devuelve un vector ordenado
vector<int> ordenado(vector<int> s);

// Ordena el vector pasado por parámetro
void ordenar(vector<int>& s);

// Devuelve un vector con elementos crecientes entre los limites por ej: range(1,6) = <1,2,3,4,5,6>
vector<int> range(int desde_inclusive, int hasta_inclusive);

// Devuelve el resultado de concatenar los vectores, por ej: concatenar(<1,2,3>,<4,5,6>) = <1,2,3,4,5,6>
vector<int> concatenar(vector<int> s, vector<int> t);

#endif //LECTURADECEREBROS_AUXILIARES_H
