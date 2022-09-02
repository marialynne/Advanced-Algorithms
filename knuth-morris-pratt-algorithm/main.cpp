#include<bits/stdc++.h>
using namespace std;

/*
Title: Knuth Morris Pratt Algorithm (KMP)
*/

vector<int> getLPS(string pattern);
void kmpa(string text, string pattern);

int main()
{
    string text = "hola mundo mun!";
    string pattern = "munu";
    //                00101234


    kmpa(text, pattern);
}

void kmpa(string text, string pattern)
{
    int const tSize = text.length();
    int const pSize = pattern.length();
    vector<int> lps;

    lps = getLPS(pattern);
    for (int i = 0; i < pSize; i++)
        cout << pattern[i] << "  ";
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

