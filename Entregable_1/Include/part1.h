#include<bits/stdc++.h>
using namespace std;

void part1(vector<string> transmissions, vector<string> mcodes)
{
    /*
    Complejidad:
        Tiempo: O(N²)
        Espacio: O(M)
    Descripción de función:
        Función que detecta si una cadena de texto de mcode se encuntra dentro de una cadena de transmisión.
    Input:
        vector<string> transmissions
        vector<string> mcodes
    Output:
        Nada
    */

    for(int i = 0; i < transmissions.size(); i++)
    {        
        vector<int> index;

        for(int j = 0; j < mcodes.size(); j++)
        {
            index = kmpa(transmissions[i], mcodes[j]);

            if(index.empty()) cerr << "\033[1;31m(false)\033[0m\tEl archivo transmission" << i+1 << ".txt no contiene el código \033[1;33m\"" + mcodes[j] + "\"\033[0m del archivo mcode" << j+1 << ".txt" << endl; 
            else 
            {
                cout << "\033[1;32m(true)\033[0m\tEl archivo transmission" <<i+1<< ".txt sí contiene el código \033[1;33m\"" + mcodes[j] + "\"\033[0m del archivo mcode" << j+1 << ".txt";
                cout << " \tEn índice(s): ";
                for(int i : index) 
                    cout << i << " ";
                cout << endl;
            }
        }
    }
}