/*

1 dia = 1440 martes
2 dias = 2880 miercoles
3 dias = 4320 jueves
4 dias = 5760 viernes

Clases
1   (540 - 660) (3420 - 3420)
2   (2040 - 2160)  ()
3 
4
5
6
7
8
*/
#include<bits/stdc++.h>
using namespace std;

void getDay(int n)
{
    map<int, string> days = {
        {0, "Monday"},
        {1, "Tuesday"},
        {2, "Wednesday"},
        {3, "Thursday"},
        {4, "Friday"}
    };
    
    cout << days.find(n) << endl;
}

int main()
{
    getDay(1);
}

