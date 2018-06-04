#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
using namespace std;
typedef vector<vector<int> > matriz;
typedef vector<int> Vector;

int cantOperaciones = 0 ;

Vector vectorColumna(matriz B, int i){
    Vector respuesta;
    int j = 0;
    for (j  = 0 ;  j < B.size(); j++){
        respuesta.push_back(B[j][i]);
        cantOperaciones++;
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
            cantOperaciones++;
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

matriz multiplicarMatrizConMatriz ( matriz A, matriz B){
    matriz C;
    int i=0;
    for(i = 0; i < A.size(); i++){
        Vector fila;
        fila = multiplicarVectorContraMatriz(A[i],B);
        C.push_back(fila);
    }
    return C;
}

matriz recursividad( matriz A, int n){
    if(n==2){
        matriz resultado = multiplicarMatrizConMatriz(A, A);
        return resultado;
    }
    else if( n > 2){
        if( n%2 ==0 ){
            matriz potencia = recursividad(A, n/2);
            matriz resultado = multiplicarMatrizConMatriz(potencia, potencia);
            return resultado;
        } else{
            matriz potencia = recursividad(A, n-1);
            matriz resultado = multiplicarMatrizConMatriz(potencia, A);
            return resultado;
        }
    }
}

int main() {
    matriz A;
    Vector fila1 ;
    fila1.push_back(1);
    fila1.push_back(-5);
    fila1.push_back(4);

    Vector fila2 ;
    fila2.push_back(-3);
    fila2.push_back(2);
    fila2.push_back(4);

    Vector fila3 ;
    fila3.push_back(3);
    fila3.push_back(-5);
    fila3.push_back(-3);

    A.push_back(fila1);
    A.push_back(fila2);
    A.push_back(fila3);

    matriz multi = recursividad(A, 5798);
    cout << "listo" << endl;
    cout << "cantidad de operaciones : "<<cantOperaciones << endl;
    return 0;

}