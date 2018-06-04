#include <iostream>

#include <vector>
#include <tuple>
#include <cmath>
using namespace std;
typedef vector<vector<int> > matriz;
typedef vector<int> Vector;

int algoritmo2(matriz m, int x){
    int i = 0;
    int j = m[0].size() -1 ;
    int cantAp = 0 ;
    for ( j = m[0].size() -1; j > -1; j--){
        while( m[i][j] != x && i < m.size()-1){
            i++;
        }
        while(m[i][j] == x){
            cantAp++;
            i++;
            if(i == m.size()){
                break;
            }
        }
        i = 0;
    }
    return cantAp;
}

int main() {
    matriz A;
    Vector fila1;
    fila1.push_back(1);
    fila1.push_back(3);
    fila1.push_back(5);
    fila1.push_back(8);
    fila1.push_back(10);
    fila1.push_back(15);

    Vector fila2;
    fila2.push_back(4);
    fila2.push_back(10);
    fila2.push_back(20);
    fila2.push_back(21);
    fila2.push_back(24);
    fila2.push_back(26);

    Vector fila3;
    fila3.push_back(6);
    fila3.push_back(11);
    fila3.push_back(20);
    fila3.push_back(22);
    fila3.push_back(26);
    fila3.push_back(27);

    Vector fila4;
    fila4.push_back(7);
    fila4.push_back(12);
    fila4.push_back(20);
    fila4.push_back(23);
    fila4.push_back(26);
    fila4.push_back(28);

    Vector fila5;
    fila5.push_back(7);
    fila5.push_back(15);
    fila5.push_back(22);
    fila5.push_back(26);
    fila5.push_back(27);
    fila5.push_back(28);

    Vector fila6;
    fila6.push_back(10);
    fila6.push_back(20);
    fila6.push_back(22);
    fila6.push_back(26);
    fila6.push_back(28);
    fila6.push_back(29);

    A.push_back(fila1);
    A.push_back(fila2);
    A.push_back(fila3);
    A.push_back(fila4);
    A.push_back(fila5);
    A.push_back(fila6);

    int c = algoritmo2(A, 26);

    cout <<"cant de apariciones de 26 : "<< c <<endl;

    int d = algoritmo2(A, 10);

    cout <<"cant de apariciones de 10 : "<< d <<endl;

    int e = algoritmo2(A, 22);

    cout <<"cant de apariciones de 22 : "<< e <<endl;

    int f = algoritmo2(A, 20);

    cout <<"cant de apariciones de 20 : "<< f <<endl;

    return 0;
}