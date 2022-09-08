#include<bits/stdc++.h>
using namespace std;

string random_string()
{
    /*
    Complejidad:
        Tiempo: O(N)
        Espacio: O(M)
    Descripción de función:
        Función que retorna un sting random con valores de una biblioteca de letras.
    Input:
        Nada
    Output:
        String -> random string
    */

    char dictionary[] = {'1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    srand((unsigned)clock());
    string str;

    for(int i = 0; i < 1+(rand() % 10000) ; i++)
        str += dictionary[rand() % (sizeof(dictionary)/sizeof(dictionary[0]))];

    return str;
}

