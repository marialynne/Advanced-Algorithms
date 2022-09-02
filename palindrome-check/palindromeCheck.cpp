/*
Title: Palindrome-check
By: Manu
*/

#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string str);

int main()
{
    string str = "aannaa";

    if(isPalindrome(str)) cout << "Es palindromo" << endl;
    else cout << "No es palindromo" << endl;
}

bool isPalindrome(string str) 
{
	/*
	Complejidad:
		Tiempo: O(n)
		Espacio O(n)
	Descripctión:
		Función determina su una cadena de texto es palindromo.
	Input: 
		string str -> cadena de textp
	Output:
		bool -> Palindromo
	*/
    return equal(begin(str), end(str), rbegin(str)); 
}
