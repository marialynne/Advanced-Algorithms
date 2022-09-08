#include<bits/stdc++.h>
using namespace std;

string readData(string dir, bool transmission)
{
    /*
    Complejidad:
        Tiempo: O(N)
        Espacio: O(N)
    Descripción de función:
        Función que retonrna un vector con el contenido de un archivo.
    Input:
        string dir -> Dirección del archivo
    Output:
        string data -> Datos del archivo
    */
    
    string line;
    string data;
    ifstream myfile(dir);

    if (myfile.is_open())
    {
        while (getline (myfile,line))
            data += line; if(transmission) data+="#";

        myfile.close();
    }

    return data;
}