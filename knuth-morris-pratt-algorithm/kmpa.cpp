/*
Title: Knuth Morris Pratt Algorithm (KMP)
By: Manu
*/

#include<bits/stdc++.h>
using namespace std;

// Functions
vector<int> getLPS(string substr);
vector<int> kmpa(string str, string substr);

int main()
{
    string str = "Hola mundo mun mun!";
    string substr = "mun";
    vector<int> index = kmpa(str, substr);

    if(index.empty()) cout << "No se encontró patrón en el texto." << endl;
    
    for(int i : index) 
        cout << "Se encontró patrón en index = " << i << endl;
}

vector<int> kmpa(string str, string substr) 
{
    /*
    Complejiodad:
        Tiempo: O(N+M)
        Espacio: O(M)
    Descripción de función:
        Función que implementa Knuth Morris Pratt Algorithm 
        para ecnontrar patrones en una cadena de texto.
    Input:
        string str -> Cadena de text
        string substr -> Patrón
    Output:
        vector<int> -> Indeces
    */

    vector<int> lps = getLPS(substr);
    vector<int> index;
    int i=0;
    int j=0;

    if(substr.size() > str.size()) return index;

    while(i < str.size())
    {
        if(str[i] == substr[j])
        {
            if(j == substr.size()-1) index.push_back(i-2);
            i++; j++;
        }
        else if(j > 0)
        {
            j = lps[j-1]+1;
        }
        else
        {
            i++;
        }
    }

    return index;
}

vector<int> getLPS(string substr) 
{
    /*
    Complejidad:
        Tiempo: O(N)
        Espacio: O(N)
    Descripción de función:
        Función que obtiene el LPS de una cadena de texto.
    Input:
        string substr -> Patrón
    Output:
        vector<int> lps -> lps del patrón
    */

    vector<int> lps(substr.size(),-1);
    int i = 1;
    int j = 0;

    while(i < substr.size())
    {
        if(substr[i] == substr[j]) lps[i++] = j++;
        else if(j > 0) j = lps[j-1]+1;
        else i++;
    }
   
    return lps;
}

