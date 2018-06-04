#include <iostream>

int Collatz(int n){
    int count = 0;
    while(n != 1){
        if(n%2 ==0){
            n = n/2;
        }
        else{
            n = 3*n +1;
        }
        count ++;
    }
    return count;
}

void CollatzRecursivo(int n, int& count){
    count = 0;
    if(n==1){
        count = 0;
    }
    else{
        if(n%2 ==0){
            CollatzRecursivo(n/2,count);
        }
        else{
            CollatzRecursivo(3*n+1,count);
        }
        count++;
    }
}

int main() {
    int entero;
    std::cin >> entero ;
    int cantPasos;
    int count;
    cantPasos = Collatz(entero);
 //   CollatzRecursivo(entero,count);
    std::cout << "La cantidad de pasos usando Collatz fue " <<cantPasos << std::endl;
 //   std::cout << "La cantidad de pasos usando Collatz Recursivo fue " << count << std::endl;

    return 0;
}