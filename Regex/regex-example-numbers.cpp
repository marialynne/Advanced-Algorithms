#include<bits/stdc++.h>
using namespace std;

int main()
{
    string input = "hola"; //  Aqui pones lo que quieres, puedes poner numeros porque al final es ascii 

    string int_num = "^0$|^[1-9][0-9]*$";


    regex pattern(int_num);

    if(regex_match(input, pattern))
        cout << "matched\n";
    else
        cout << "not matched\n";

}