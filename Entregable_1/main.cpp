/*
Title: 
*/
#include "Include/kmp.h"
#include "Include/palindromeCheck.h"
#include "Include/longestPalindromicSubstring.h"
#include "Include/randomString.h"
#include "Include/writeData.h"
#include "Include/readData.h"
#include "Include/longestCommonSubsequence.h"
#include "Include/part1.h"
#include "Include/part2.h"
#include "Include/part3.h"

#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> transmissions, mcodes;
    string transmission1 = "Input/transmission1.txt";
    string transmission2 = "Input/transmission2.txt";
    string mcode1 = "Input/mcode1.txt";
    string mcode2 = "Input/mcode2.txt";
    string mcode3 = "Input/mcode3.txt";

        // This part of the code is just for testing, it is commented at the end
        int lines = 10;
        writeData(transmission1, lines);
        writeData(transmission2, lines);
        // To here

    /* transmissions.push_back(readData(transmission1,true));
    transmissions.push_back(readData(transmission2,true));
    mcodes.push_back(readData(mcode1,false));
    mcodes.push_back(readData(mcode2,false));
    mcodes.push_back(readData(mcode3,false)); */

    // Part 1   
    cout << "Parte 1" << endl;
    //part1(transmissions, mcodes);

    // Part 2
    cout << "\nParte 2" << endl;
    part2(transmissions);

    // Part 3
    cout << "\nParte 3" << endl;
    vector<char> l = longestCommonSubsequence(transmissions[0], transmissions[1]);
    for (int i = 0; i < l.size(); i++)
        cout << l[i];
    cout << endl;

}
