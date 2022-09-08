#include<bits/stdc++.h>
using namespace std;

vector<string> longestPalindromicSubstring(string str) 
{
    int len = str.length(), prev, next, first, second;
    string palindrome = string(1, str[0]), substr = "";

    for(int i = 0; i < len; i++) 
    {                                                   //01x3  
        if(str[i-1] == str[i]) prev = i-2, next = i+1; // anna
        else prev = i-1; next = i+1; // ana
           
        while(prev >= 0 && next < len) 
        {
            char prevCH = str[prev];
            char nextCH = str[next];
            if(prevCH == nextCH) prev--, next++;
            else break;
        }
        
        substr = string(str.begin() + prev + 1, str.begin() + next);

        if(substr.length() > palindrome.length()) 
        {
            palindrome = substr; first = prev + 1; second = next; 
        }
    }

    return {palindrome, to_string(first), to_string(second)};
}

int main() 
{
    vector<string> cases = {"AABCDCBCDCAA", "ABCAABCAAC", "ABBACABBACAAB"};
    for (int i = 0; i < cases.size(); i++)
    {
        vector<string> palindrome = longestPalindromicSubstring(cases[i]);
        cout<<"Original: " << cases[i] << "\t\tPalindrome: " << palindrome[0] << "\tP1: " << palindrome[1] << " P2: " << palindrome[2] << endl;
    }
}