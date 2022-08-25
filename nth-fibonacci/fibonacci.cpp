/*
    Encontrar el número más cercano dentro la cadena de Fibonacci dado N
*/

#include<bits/stdc++.h>
using namespace std;

int fibonacci(int n, int previus, int next);
int aux=0;

int main() {
    int n = 1;
    int ans = fibonacci(n,0,1);
    cout << "El número Fibonacci menor al número dado es: " << ans << endl;
}

int fibonacci(int n, int previus, int next) {

    if(n <= 1) return n;
    
    aux = previus + next;

    cout << next << "\tn:" << n << endl;

    if(n > aux) 
        aux = fibonacci(n,next,aux);
    else 
        return next;

    return aux;
}