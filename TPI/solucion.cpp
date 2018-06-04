#include "auxiliares.h"
#include "ejercicios.h"
#include <tuple>
#include <math.h>

bool esValida(senial s){
    bool result = true;
    if(s.size() == 0){
        result = false;
    }
    int i = 0;
    for (i=0; i < s.size(); i++){
        if(s[i] > pow(2,15) -1  || s[i] <- pow(2,15)){
            result = false;
        }
    }
    return result;
}

float media(senial s){
    float promedio = 0;
    int i = 0;
    for (i = 0; i < s.size(); i++){
        promedio += abs(s[i]);
    }
    promedio = promedio/s.size();
    return promedio;
}

vector<int> ctrlf(senial s, int x){
    vector<int> res;
    int i = 0;
    for (i = 0; i < s.size();i++){
        if(s[i] == x){
            res.push_back(i);
        }
    }
    return res;
}

int maximo(senial s, int& latencia){
    int posicion = 0;
    int maximo = s[0];
    int i = 0;
    for(i = 1; i < s.size(); i++){
        if(s[i] > maximo){
            maximo = s[i];
            posicion = i;
        }
    }
    latencia = posicion;
    return maximo;
}

int medianaEntera(senial s, int& latencia){
    int mediana = 0 ;
    vector<int> vector_ordenado = ordenado(s);
    if(s.size() % 2 ==0){
        mediana = vector_ordenado[s.size()/2 -1];
    }
    else{
        mediana = vector_ordenado[(s.size()-1)/2];
    }
    int j = 0;
    while(s[j] != mediana){
        j++;
    }
    latencia = j;
    return mediana;
}

tuple<vector<int>,vector<float> > histograma(senial s, int bins){
    senial ordenada = ordenado(s);
    vector<float> limites;
    int i = 0;
    for(i =0; i <= bins; i++){
        limites.push_back( (float) ((ordenada[ordenada.size()-1]-ordenada[0])*i )/ (float) bins + ordenada[0] );
    }

    vector<int> cuentas (limites.size()-1,0);
    int j = 0;
    for( j=0; j < s.size(); j++){
        int k = 0;
        for(k=0; k <= limites.size()-3; k++){
            if( s[j] >= limites[k] && s[j]<limites[k+1]){
                cuentas[k]++;
            }
        }
        if( limites[limites.size()-2] <= s[j] && s[j] <= limites[limites.size() -1] ){
            cuentas[limites.size()-2]++;
        }
    }
    tuple< vector<int>,vector<float> > res = std::make_tuple (cuentas, limites);
    return res;
}

float distanciaEuclidiana(senial p, senial q){
    float distancia = 0;
    int i = 0;
    for(i = 0; i< p.size(); i++){
        distancia += pow((p[i]-q[i]),2);
    }
    distancia = sqrt(distancia);
    return distancia;
}

tuple< promedios, ventanas > slidingWindows(senial s, vector<int> tamanios){
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

bool pertenece(int x, vector<int> s){
    int k = 0;
    for (k=0; k< s.size(); k++){
        if(s[k] == x){
            return true;
        }
    }
    return false;
}

bool sonTodosMissingALaDerecha(senial s, vector<int> missings, int i){
    int j = i+1;
    for( j = i+1; j < s.size(); j++){
        if( !pertenece(j, missings) ){
            return false;
        }
    }
    return true;
}

bool sonTodosMissingALaIzquierda(senial s, vector<int> missings, int i){
    int j = i-1;
    for( j = i-1; j < s.size(); j--){
        if( !pertenece(j, missings) ){
            return false;
        }
    }
    return true;
}

int devolverElMasCercanoALaIzquierda(senial s, vector<int> missings, int i){
    int j = i-1;
    for (j = i-1; j >-1; j--){
        if(!pertenece(j, missings)){
            return s[j];
        }
    }
}

int devolverElMasCercanoALaDerecha(senial s, vector<int> missings, int i) {
    int j = i+1;
    for (j = i+1; j < s.size(); j++){
        if(!pertenece(j, missings)){
            return s[j];
        }
    }
}

int hallarExtremoDerecho(senial s, vector<int> missings, int i){
    if((i == s.size()-1) || sonTodosMissingALaDerecha(s, missings, i)){
        return devolverElMasCercanoALaIzquierda(s, missings, i);
    }
    else{
        return devolverElMasCercanoALaDerecha(s, missings, i);
    }
}

int hallarExtremoIzquierdo(senial s, vector<int> missings, int i){
    if((i == 0) || sonTodosMissingALaIzquierda(s, missings, i)){
        return devolverElMasCercanoALaDerecha(s, missings, i);
    }
    else{
        return devolverElMasCercanoALaIzquierda(s, missings, i);
    }
}

int completarHueco( senial s, vector<int> missings, int i){
    int extremoDerecho = hallarExtremoDerecho(s, missings, i);
    int extremoIzquierdo = hallarExtremoIzquierdo(s, missings, i);
    int promedioEntero = (extremoDerecho + extremoIzquierdo)/2;
    return promedioEntero;
}

void completar(senial & s, vector<int> missings){
    vector<int> aCompletar;
    if ( missings.size() < s.size() ) {
        int i = 0;
        for(i =0 ; i < s.size(); i++){
            if( pertenece(i, missings)){
                int comp = completarHueco(s, missings, i);
                aCompletar.push_back(comp);
            }
        }
        int k = 0;
        for(k = 0; k < aCompletar.size(); k++){
            s[missings[k]] = aCompletar[k];
        }
    }
}

bool esOutlier(int x, senial s){
    senial temp = ordenado(s);
    return temp[ floor(temp.size()*0.95)] < x;
}

vector<int> sacarOutliers(senial& s){
    vector<int> borrados;
    int i = 0;
    for(i=0; i < s.size();i++){
        if( esOutlier(s[i],s) ){
            borrados.push_back(i);
            s[i] = 0;
        }
    }
    return borrados;
}

tuple<float,vector<tuple<int,int> > > distanciaAcordeon(senial s, senial q){
    // Completar (OPCIONAL)
    tuple<float,vector<tuple<int,int> > > res;
    return res;
}
