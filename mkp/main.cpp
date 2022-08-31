#include<bits/stdc++.h>
using namespace std;

/*
Patrón: mun
LPS:    000

Patrón: A A B B A A D C D A
LPS:    0 1 0 1 1 2 0 0 1 1
        1 2 
*/
vector<int> getLPS(string pattern);
void mkp(string text, string pattern);

int main()
{
    string text = "hola mundo mun!";
    string pattern = "mmuunn";
    //                00101234


    mkp(text, pattern);
}

void mkp(string text, string pattern)
{
    int const tSize = text.length();
    int const pSize = pattern.length();
    vector<int> lps;

    lps = getLPS(pattern);
    for (int i = 0; i < pSize; i++)
        cout << pattern[i] << " ";
    cout << endl;
    for (int i = 0; i < pSize; i++)
        cout << lps[i] << " ";
    
    
}

vector<int> getLPS(string pattern)
{
    vector<int> lps(pattern.size(),-1);
    int i = 1;
    int j = 0;
    while(i<pattern.size())
    {
        if(pattern[i] == pattern[j]) lps[i++] = j++;
        else if(j > 0) j = lps[j-1]+1;
        else i++;
    }

       
    return lps;
}

