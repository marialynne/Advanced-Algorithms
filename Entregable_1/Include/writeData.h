//#include "../Include/randomString.h"
#include<bits/stdc++.h>
using namespace std;

void writeData(string dir, int lines)
{
    /*
    Complejidad:
        Tiempo: O(N)
        Espacio: O(M)
    Descripción de función:
        Función que indroduce datos dentro de un archivo.
    Input:
        int lines -> Cantidad de líneas dentro del archivo
        string dir -> Dirección del archivo
    Output:
        Nada
    */
    
    ifstream file(dir.c_str());
    ofstream outdata;
    outdata.open(dir);

    if(!outdata || !file.good()) 
    { 
        cerr << "Error: El archivo " + dir + " no pudo ser abierto." << endl;
        exit(1);
    }
    
    for (int i=0; i<lines; i++)
        outdata << random_string() << endl;
        
    outdata.close();
}
