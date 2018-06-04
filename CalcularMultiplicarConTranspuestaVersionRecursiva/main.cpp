#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
using namespace std;
typedef vector<vector<int> > matriz;
typedef vector<int> Vector;

matriz calcularTranspuesta (matriz A){
    int i =0;
    matriz At;
    for(i = 0; i < A[0].size(); i++){
        Vector fila;
        int j = 0;
        for ( j = 0; j < A.size(); j++){
            fila.push_back(A[i][j]);
        }
        At.push_back(fila);
    }
    return At;
}

Vector vectorColumna(matriz B, int i){
    Vector respuesta;
    int j = 0;
    for (j  = 0 ;  j < B.size(); j++){
        respuesta.push_back(B[j][i]);
    }
    return respuesta;
}

int multiplicarVectorConVector(Vector v, Vector w){
    if(v.size() != w.size()){
        cout << "error en los tamanios" <<endl;
    } else{
        int suma = 0;
        int i = 0;
        for (i= 0 ; i < v.size(); i ++ ){
            suma += v[i] * w[i];
        }
        return suma;
    }
}

Vector multiplicarVectorContraMatriz(Vector v, matriz B){
    if(v.size() == B.size()){
        Vector respuesta ;
        int i = 0;
        for(i = 0; i < B[0].size(); i++){
            Vector columna = vectorColumna(B,i);
            int resp = multiplicarVectorConVector(v, columna);
            respuesta.push_back(resp);
          }
        return respuesta;
    } else{
        cout << "error en los tamanios" <<endl;
    }
}

matriz SacarFilaAMatriz(matriz A, int k){
    matriz resultado;
    int i = 0;
    for(i = 0 ; i < A.size() ; i++){
        if( i != k){
            resultado.push_back(A[i]);
        }
    }
    return resultado;
}

matriz recursividadCuadrada( matriz A){
    if(A.size() ==1){
        Vector fila;
        int temp = multiplicarVectorConVector(A[0], A[0]);
        fila.push_back(temp);
        matriz Matriz;
        Matriz.push_back(fila);
        return Matriz;
    } else{
        matriz AmenosUtlimaFila = SacarFilaAMatriz(A,A.size()-1);
        matriz B = recursividadCuadrada(AmenosUtlimaFila);
        int i = 0;
        for( i = 0; i < B.size(); i++ ){

            int temp = multiplicarVectorConVector(A[i],A[A.size()-1]);

            B[i].push_back(temp);
        }
        Vector ultimaFila;
        int j = 0;
        for( j = 0; j < A.size(); j++){
            int temp2 = multiplicarVectorConVector(A[A.size()-1],A[j]);
            ultimaFila.push_back(temp2);
        }
        B.push_back(ultimaFila);
        return B;
    }
}

int main() {
    vector<vector<int> > A;
    vector<int> fila1 ;
    fila1.push_back(1);
    fila1.push_back(-1);

    vector<int> fila2 ;
    fila2.push_back(-1);
    fila2.push_back(1);

    A.push_back(fila1);
    A.push_back(fila2);

    matriz multi = recursividadCuadrada(A);
    cout << "listo" << endl;
    return 0;

}