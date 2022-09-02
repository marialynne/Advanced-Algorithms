#include<bits/stdc++.h>
using namespace std;

/*
Title: Knuth Morris Pratt Algorithm (KMP)
*/

vector<int> getLPS(string substr);
void kmpa(string str, string substr);

int main()
{
    string str = "Hola mundo mun mun!";
    string substr = "mun";

    kmpa(str, substr);
}

void kmpa(string str, string substr) 
{
    /*
    Complejodad:
        Tiempo: O(N+M)
        Espacio: O(M)
    Descripción de función:
        Función que implementa Knuth Morris Pratt Algorithm 
        para ecnontrar patrones en una cadena de texto.
    Input:
        string str -> Cadena de text
        string substr -> Patrón
    Output:
        Nada.
    */

    vector<int> lps = getLPS(substr);
    int i=0;
    int j=0;

    if(substr.size() > str.size()) cout << "[Error]: Patrón más grande que texto" << endl;

    while(i < str.size())
    {
        if(str[i] == substr[j])
        {
            if(j == substr.size()-1) cout << "Patrón en index: " << i-2 << endl;
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
}

vector<int> getLPS(string substr) 
{
    /*
    Complejodad:
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

