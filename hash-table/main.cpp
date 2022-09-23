#include <bits/stdc++.h>
using namespace std;

int main()
{
    string msg1 = "Esto es mi mensaje",
           msg2 = "No no no si",
           msg3 = "pos buenardo";

    vector<string> myMsgs = {msg1, msg2, msg3};
    vector<int> claves;

    int n, sum;
    for (int i = 0; i < myMsgs.size(); i++)
    {
        for (int j = 0; j < myMsgs[i].length(); j++)
        {
            n += myMsgs[i][j] * i;
            // cout << myMsgs[i][j] * i << endl;
            sum += myMsgs[i][j];
        }
        // claves.push_back(sum % 10); // Funciona
        claves.push_back(n % 10); // Más eifciente, aquí ya no hay colisiones
        // Pero chanche si choca, tons lo mejor es que aumentes tu tamaño de arreglo de llaves
        // Y por cada aumento, el mod aumental al tamaño de arreglo
    }

    for (auto i : claves)
    {
        cout << i << endl;
    }
    return 0;
}