#include <iostream>
#include <vector>
#include <math.h>
#include <tuple>
#include "auxiliares.h"
#include "ejercicios.h"
#include <tuple>
using namespace std;

typedef  vector<int> senial;
typedef  vector<tuple<int,int> > ventanas;
typedef  vector<float> promedios;


void swap (vector<int> &s, int i, int j){
    int temp = s[i];
    s[i] = s[j];
    s[j] = temp;
}

void ordenar(vector<int>& s){
    for (int i = 1; i < s.size(); i++){
        for(int j = i; j > 0 && s[j] < s[j-1]; j--){
            swap(s, j, j-1);
        }
    }
}

bool esValida(vector<int> s){
    bool result = true;
    int i = 0;
    if(s.size() == 0){
        result = false;
    }
    for (i=0; i < s.size(); i++){
        if(s[i] > 2^15 -1  || s[i] <-2^15){
            result = false;
        }
    }
    return result;

}

float esMedia(vector<int> s){
    float promedio = 0;
    int i = 0;
    for (i = 0; i < s.size(); i++){
        promedio += s[i];
    }
    promedio = promedio/s.size();
    return promedio;
}

vector<int> ctrlf(vector<int> s, int x){
    vector<int> indices;
    int i = 0;
    for (i = 0; i < s.size();i++){
        if(s[i] == x){
            indices.push_back(i);
        }
    }
    return indices;
}

vector<int> maximo(vector<int> s){
    int posicion = 0;
    int maximo = s[0];
    int i = 0;
    for(i = 1; i < s.size(); i++){
        if(s[i] > maximo){
            maximo = s[i];
            posicion = i;
        }
    }
    vector<int> resultado;
    resultado.push_back(posicion);
    resultado.push_back(maximo);
    return resultado;
}

vector<int> minimoPosicion(vector<int> s){
    int posicion = 0;
    int minimo = s[0];
    int i = 0;
    for(i = 1; i < s.size(); i++){
        if(s[i] < minimo){
            minimo = s[i];
            posicion = i;
        }
    }
    vector<int> resultado;
    resultado.push_back(posicion);
    resultado.push_back(minimo);
    return resultado;
}

vector<int> subVector(int i, int j, vector<int> s){
    vector<int> sub_vector;
    int k = i;
    for(k = i; k < j; k++){
        sub_vector.push_back(s[k]);
    }
    return sub_vector;
}

vector<int> ordenarVector(vector<int> s ){
    int i = 0;
    vector<int> vector_ordenado = s;
    for (i = 0; i < s.size(); i++){
        vector<int> sub_vector = subVector(i, s.size(), vector_ordenado);
        vector<int> minimo = minimoPosicion(sub_vector);
        int tmp = vector_ordenado[i];
        vector_ordenado[i] = minimo[1];
        vector_ordenado[minimo[0] + i] = tmp;
    }
    return vector_ordenado;
}

vector<int> medianaEntera(vector<int> s){
    int latencia = 0 ;
    int mediana = 0 ;
    vector<int> vector_ordenado = ordenarVector(s);
    if(s.size() % 2 ==0){
        mediana = vector_ordenado[s.size()/2 -1];
    }
    else{
        mediana = vector_ordenado[(s.size()-1)/2];
    }
    bool buscando_latencia = true;
    int j = 0;
    while(buscando_latencia){
        if(s[j] == mediana){
            buscando_latencia = false;
            latencia = j;
        }
        j++;
    }
    vector<int> resultado;
    resultado.push_back(latencia);
    resultado.push_back(mediana);
    return resultado;
}

float distanciaEuclideana(vector<int> s, vector<int> q){
    float distancia = 0;
    int i = 0;
    for(i = 0; i< s.size(); i++){
        distancia += (s[i]-q[i])^2;
    }
    distancia = sqrt(distancia);
    return distancia;
}
/*
void slidingWindows(vector<int> s, vector<int> tamanios){
    vector< vector< int > > ventanas;
    int i = 0;
    for(i = 0; i < tamanios.size(); i++){
        int start = 0;
        while(start < s.size()){
            vector<int> ventana;
            ventana.push_back(start);
            ventana.push_back(start+tamanios[i]-1);
            ventanas.push_back(ventana);
            start += tamanios[i];
        }
    }
    vector<float> promedios;
    int j =0;
    for(j =0; j < ventanas.size(); j++){
        float promedio = 0;
        int k = ventanas[j][0];
        for(k = ventanas[j][0]; k <= ventanas[j][1]; k++){
            if(k > s.size()-1){
                promedio += s[s.size()-1];
            }
            else{
                promedio += s[k];
            }
        }
        promedio = promedio / (ventanas[j][1] - ventanas[j][0] + 1);
        promedios.push_back(promedio);
    }
    std::cout <<"listo" <<std::endl;
};*/

tuple< promedios, ventanas > slidingWindows2(senial s, vector<int> tamanios){
    ventanas VENTANAS;
    int i = 0;
    //calculo las ventanas
    for(i = 0; i < tamanios.size(); i++){
        int start = 0;
        while(start < s.size()){
            tuple<int, int> ventana = std::make_tuple (start, start+tamanios[i]-1);
            VENTANAS.push_back(ventana);
            start += tamanios[i];
        }
    }
    promedios PROMEDIOS;
    int j =0;
    //calculo los promedios
    for(j =0; j < VENTANAS.size(); j++){
        float promedio = 0;
        int k = get<0>(VENTANAS[j]);
        for(k = get<0>(VENTANAS[j]); k <= get<1>(VENTANAS[j]); k++){
            if(k > s.size()-1){
                promedio += s[s.size()-1];
            }
            else{
                promedio += s[k];
            }
        }
        promedio = promedio / ( get<1>(VENTANAS[j]) - get<0>(VENTANAS[j]) + 1);
        PROMEDIOS.push_back(promedio);
    }
    tuple<promedios, ventanas> res = std::make_tuple (PROMEDIOS, VENTANAS);
    return res;
}

int main() {
    vector<int> prueba1;
    prueba1.push_back(4);
    prueba1.push_back(-1);
    prueba1.push_back(0);
    prueba1.push_back(-5);
    prueba1.push_back(3);
    prueba1.push_back(1);
    prueba1.push_back(-7);
    ordenar(prueba1);
    vector<int> ordenado = ordenarVector(prueba1);
    vector<int> resultado = medianaEntera(prueba1);
    vector<int> controlf = ctrlf(prueba1,-5);
    vector<int> prueba2;
    prueba2.push_back(33);
    prueba2.push_back(25);
    prueba2.push_back(-1);
    prueba2.push_back(3);
    prueba2.push_back(1);
    vector<int> tamanios;
    tamanios.push_back(3);
    tamanios.push_back(2);

    tuple< promedios, ventanas > responseX;
    responseX = slidingWindows2(prueba2,tamanios);
    cout << "Hello, World!" << endl;
    int entero;
    std::cin >> entero;
    return 0;
}