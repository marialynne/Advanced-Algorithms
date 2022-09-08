#include<bits/stdc++.h>
using namespace std;

void part2(vector<string> transmissions)
{
    vector<vector<string>> palindrome;

    for(int i = 0; i < transmissions.size(); i++)
    {
        palindrome.push_back(longestPalindromicSubstring(transmissions[i]));
        cout << "posiciónInicial: \033[1;33m" << palindrome[i][1] <<  "\033[0m posiciónFinal: \033[1;33m"<< palindrome[i][2] << "\033[0m  (para archivo de transmisión" << i+1 << "): \033[1;33m" << palindrome[i][0] << "\033[0m" << endl;
    }
}