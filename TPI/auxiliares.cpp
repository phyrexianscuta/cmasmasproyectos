#include "auxiliares.h"

void swap (vector<int> &s, int i, int j){
    int temp = s[i];
    s[i] = s[j];
    s[j] = temp;
}

vector<int> ordenado(vector<int> s){
    vector<int> res = s;
    for (int i = 1; i < res.size(); i++){
        for(int j = i; j > 0 && res[j] < res[j-1]; j--){
            swap(res, j, j-1);
        }
    }
    return res;
}

void ordenar(vector<int>& s){
    for (int i = 1; i < s.size(); i++){
        for(int j = i; j > 0 && s[j] < s[j-1]; j--){
            swap(s, j, j-1);
        }
    }
}

vector<int> range(int desde_inclusive, int hasta_inclusive){
    vector<int> res;
    for(int i = desde_inclusive; i < hasta_inclusive+1; i++){
        res.push_back(i);
    }
    return res;
}

vector<int> concatenar(vector<int> s, vector<int> t){
    vector<int> res;
    for(int i = 0; i < s.size(); i++){
        res.push_back(s[i]);
    }
    for(int j = 0; j < t.size(); j++){
        res.push_back(t[j]);
    }
    return res;
}