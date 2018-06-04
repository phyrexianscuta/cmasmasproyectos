#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
using namespace std;
typedef vector<vector<int> > matriz;
typedef vector<int> Vector;
typedef tuple<int,int> posicion;
typedef vector<tuple<int,int> > vectDeCoordenadas;

bool esValle(posicion p, matriz A){
    int i = get<0>(p);
    int j = get<1>(p);
    if(j+1 < A[0].size() && A[i][j+1]< A[i][j]){
        return false;
    }
    else if(j-1 >=0 && A[i][j-1] < A[i][j]){
        return false;
    }
    else if( i-1 >=0 && A[i-1][j] < A[i][j]){
        return false;
    }
    else if(i+1 < A.size() && A[i+1][j] < A[i][j]){
        return false;
    }
    return true;
}

vectDeCoordenadas vectoresAdyacentes(posicion p, matriz A){
    vectDeCoordenadas resp;
    int i = get<0>(p);
    int j = get<1>(p);
    if(j+1 < A[0].size()){
        posicion adyacente = std::make_tuple (i, j+1);
        resp.push_back(adyacente);
    }
    if(j-1 >=0){
        posicion adyacente = std::make_tuple (i, j-1);
        resp.push_back(adyacente);
    }
    if( i-1 >=0){
        posicion adyacente = std::make_tuple (i-1, j);
        resp.push_back(adyacente);
    }
    if(i+1 < A.size()){
        posicion adyacente = std::make_tuple (i+1, j);
        resp.push_back(adyacente);
    }
    return resp;
}

vectDeCoordenadas coorDeMenorAltura( vectDeCoordenadas m, posicion p, matriz A){
    int l=0;
    vectDeCoordenadas resp;
    int p1 = get<0>(p);
    int p2 = get<1>(p);
    for(l = 0 ; l < m.size(); l ++){
        int w1 = get<0>(m[l]);
        int w2 = get<1>(m[l]);
        if(A[w1][w2] < A[p1][p2]){
            resp.push_back(m[l]);
        }
    }
    return resp;
}

posicion hallarMinimoEntreVarios( vectDeCoordenadas m, matriz A ){
    int pos = 0;
    int p1 = get<0>(m[0]);
    int p2 = get<1>(m[0]);
    int minimo = A[p1][p2];
    int  i =0;
    for( i = 0 ;  i < m.size(); i++){
        int q1 = get<0>(m[i]);
        int q2 = get<1>(m[i]);
        if(A[q1][q2]<minimo){
            pos = i ;
            minimo = A[q1][q2];
        }
    }
    return m[pos];
}

posicion rec(posicion p , matriz A){
    if(esValle(p,A)){
        return p;
    } else{
        vectDeCoordenadas adyacentes = vectoresAdyacentes(p, A);
        vectDeCoordenadas adyacentesDeMenorAltura = coorDeMenorAltura(adyacentes, p, A);
        vectDeCoordenadas posiblesSoluciones;
        int k = 0;
        for(k = 0; k < adyacentesDeMenorAltura.size(); k++){
            posicion q = rec(adyacentesDeMenorAltura[k],A);
            posiblesSoluciones.push_back(q);
        }
        posicion menorValle = hallarMinimoEntreVarios ( posiblesSoluciones, A);
        return menorValle;
    }
}

int main() {

     matriz mapa;
     Vector fila1;
     Vector fila2;
     Vector fila3;
     Vector fila4;
     Vector fila5;
     fila1.push_back(10);
     fila1.push_back(17);
     fila1.push_back(9);
     fila1.push_back(13);
     fila1.push_back(5);
     fila1.push_back(23);

     fila2.push_back(4);
     fila2.push_back(8);
     fila2.push_back(6);
     fila2.push_back(1);
     fila2.push_back(11);
     fila2.push_back(2);

     fila3.push_back(28);
     fila3.push_back(30);
     fila3.push_back(14);
     fila3.push_back(3);
     fila3.push_back(7);
     fila3.push_back(12);

     fila4.push_back(24);
     fila4.push_back(25);
     fila4.push_back(26);
     fila4.push_back(32);
     fila4.push_back(31);
     fila4.push_back(40);

     fila5.push_back(15);
     fila5.push_back(18);
     fila5.push_back(16);
     fila5.push_back(20);
     fila5.push_back(-1);
     fila5.push_back(-2);
     mapa.push_back(fila1);
     mapa.push_back(fila2);
     mapa.push_back(fila3);
     mapa.push_back(fila4);
     mapa.push_back(fila5);
     posicion startingPoint = std::make_tuple (3, 3);
     posicion menorValle = rec(startingPoint, mapa);
     std::cout << "Listo! " << std::endl;
     return 0;
}