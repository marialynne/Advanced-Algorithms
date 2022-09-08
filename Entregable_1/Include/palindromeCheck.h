/*
Title: Palindrome-check
By: Manu
*/

#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string str) 
{
	/*
	Complejidad:
		Tiempo: O(n)
		Espacio O(n)
	Descripctión:
		Función determina su una cadena de texto es palíndromo.
	Input: 
		string str -> cadena de texto
	Output:
		bool -> Palíndromo
	*/

	// Opción 1
    // return equal(begin(str), end(str), rbegin(str)); 

	// Opción 2
	int len = str.length();
	for(int i=0; i< len/2; i++)
		if(str[i] != str[len-1-i]) return false;
	return true;
}

