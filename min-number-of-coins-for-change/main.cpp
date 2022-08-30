#include <bits/stdc++.h>

using namespace std;

void Procedencia(bool **P, int **C, int &L, int &n, int *T)
{
    // Complejidad O(n²)
    const int infinito = numeric_limits<int>::max(); //Máximo valor que puede almacenar un Int.
    int i, j;
    for (i = 0; i < n; i++)
    {
        P[i][0] = false;
        C[i][0] = 0;
    }
    for (i = 0; i < n; i++)
    {
        for (j = 1; j <= L; j++)
        {
            if (i == 0 && j < T[i])
            {
                C[i][j] = infinito;
                P[i][j] = false;
            }
            else if (i == 0)
            {
                C[i][j] = 1 + C[i][j - T[0]];
                P[i][j] = true;
            }
            else if (j < T[i])
            {
                C[i][j] = C[i - 1][j];
                P[i][j] = false;
            }
            else
            {
                C[i][j] = min(C[i - 1][j], 1 + C[i][j - T[i]]);
                P[i][j] = C[i][j] != C[i - 1][j];
            }
        }
    }
}

void Monedas(bool **P, int **C, int &L, int &n, int *T, int *monedas)
{
    //Complejidad O(n!)
    int i = n - 1;
    int j = L;
    for (int ind = 0; ind < n; ind++)
    {
        monedas[ind] = 0;
    }
    while (i != -1 && j != 0)
    {
        if (P[i][j] == false)
        {
            i--;
        }
        else
        {
            monedas[i] = monedas[i] + 1;
            j = j - T[i];
        }
    }
    if (i == 0)
    {
        monedas[0] = C[i][j] + monedas[0];
    }
}

void imprimirSolucion(int *T, int *monedas, int &n)
{
    // Complejidad: O(n²)
    for (int i = 0; i < n; i++)
    {
        if (monedas[i] != 0)
        {
            cout << monedas[i] << " monedas/billetes de tipo " << T[i] << endl;
        }
    }
}

void problemaCambio(int &n, int &p, int &q, int T[])
{
    // Complejidad: O(n²)
    int L = q - p;

    int monedas[n]; //Arreglo solución para indicar la cantidad que se toma por cada moneda T[i].
    int **C = new int *[n]; //Matriz que almacena los cálculos para obtener el número mínimo de monedas.
    bool **P = new bool *[n]; //Matriz booleana que indica si se ha tomado la moneda T[i] en el valor C[i][j].

    //Creación de matrices dinámicas.
    for (int i = 0; i < n; i++)
    {
        C[i] = new int[L + 1];
        P[i] = new bool[L + 1];
    }

    Procedencia(P, C, L, n, T);
    Monedas(P, C, L, n, T, monedas);
    imprimirSolucion(T,monedas,n);

    //Limpia la memoria, eliminando las matrices dinámicas creadas anteriormente.
    for (int i = 0; i < n; i++)
    {
        delete[] C[i];
        delete[] P[i];
    }
    delete[] C;
    delete[] P;
}

int main()
{
    int n,p,q;
    int T[] = {1,2,5,10}; //Arreglo tipos de monedas, tienen que estar ordenadas de menor a mayor monto.
    cout << "Ingrese N: ";
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cout << i+1 <<": ";
        cin >> T[i];
        cout << endl;
    }
    cout << "Ingrese (P) Precio de producto): ";
    cin >> p;
    cout << "Ingrese (Q) Billete o moneda con el que pagará: ";
    cin >> q;
    
    if(p > q)
    {
        cout << "\nSaldo insuficiente" << endl;
    }
    else if(p == q)
    {
        cout << "\nPago exacto del producto" << endl;
    }
    else {
        cout << "\nSu cambio es: " << endl;
        problemaCambio(n,p,q,T);
        cout << endl;
    }
    return 0;
}