#include <bits/stdc++.h>
using namespace std;

bool validarCaracteres(string input)
{
    string int_num = "^[A-F0-9]*$"; //   A -F 0 9

    regex pattern(int_num);

    if (regex_match(input, pattern))
        return true;
    else
        return false;
}

int main()
{
    cout << validarCaracteres("1234567890ABD1234567") << endl;
    cout << "Es: "
         << "ñ";
    return 0;
}
