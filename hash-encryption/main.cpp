#include <bits/stdc++.h>
using namespace std;
/*
    Created by Manuel Camacho
    "Hash String"

        Entrada: Un archivo de texto, seguido de un entero n
        n = multiplo de 4 (16 <= n <= 64)

        Salida: Cadena de texto de representación hexadecimal que corresponde
        al hasheo del archivo de texto de entrada.

    El entero n determina el número de columnas que contendrá una tabla donde se irán
    acomodando los caracteres del archivo de texto(incluyendo saltos de línea)
    en los renglones que sean necesarios.

    Si el número de caracteres en el archivo de texto no es
    mutiplo de n, el ultimo renglon se rellena con el valor n

    En un arreglo "a" de longitud "n" se calcula a[i] = (la suma de los ASCII
    de cada char en la columna ) % 256

    La salida se genera concatenando la representación hexadecimal
    (Mayúsculas) a dos dígitos de cada posición en el arreglo.
    La longitud de la cadena de salida será de n/4

    Pasos:
    1) Pide el archivo, leelo, y sacalo de una forma
    2) Haz una matriz de n columnas con las rows necesarias
    3) rellena le matriz con el input y lo que falte para llenar la matirz haslo con el valor n
    4) suma las columnas
    5) suma en pares de 4 los resultados de las sumas
    6) Pasalo a hexadecimal
    7) A comer papito que ya hace hambre
    ...
*/

string readData(string dir);
bool validateN(int n);
void hashEncryption(tuple<string, int> data);
string toHex(int ascii);

int main()
{
    string dir = "Archivo.txt";
    tuple<string, int> data;

    get<0>(data) = readData(dir);
    cout << "\nType n: ";
    cin >> get<1>(data);

    if (validateN(get<1>(data)))
        hashEncryption(data);

    return 0;
}

string readData(string dir)
{
    /*
    Complejidad:
    - Tiempo: O(N)
    - Espacio: O(N)
    */

    string line, data, data2;
    ifstream myfile(dir);
    char mychar;

    if (!(myfile.peek() == std::ifstream::traits_type::eof()))
        cout << "\n\n[SUCCESSFUL]: The file " + dir + " was read correctly, and has at least one character, including line breaks or spaces" << endl;
    else
    {
        cout << "\n\n[ERROR]: The file " + dir + " is empty" << endl;
        exit(0);
    }

    if (myfile.is_open())
    {
        while (myfile)
        {
            mychar = myfile.get();
            data += mychar;
        }
    }

    return data.substr(0, data.size() - 1);
}

bool validateN(int n)
{
    /*
    Complejidad:
    - Tiempo: O(1)
    - Espacio: O(1)
    */
    if ((16 <= n && n <= 64) && (n % 4 == 0))
    {
        cout << "\n[SUCCESSFUL]: n is a multiple of 4 and (16 <= n <= 64)" << endl;
        return true;
    }
    else
        cout << "\n[ERROR]: n must be a multiple of 4 and (16 <= n <= 64)" << endl;

    return false;
}

void hashEncryption(tuple<string, int> data)
{
    /*
    Complejidad:
    - Tiempo: O(N^2)
    - Espacio: O(N^2)
    */
    double size = get<0>(data).size();
    int rows = ceil(size / get<1>(data)); // Number of rows
    int cols = get<1>(data);              // Number of cols

    int a[get<1>(data)] = {0};                          // Sum of cols
    int groups[get<1>(data) / 4] = {0};                 // Groups
    vector<vector<int>> grid;                           // Matrix
    grid.resize(rows, vector<int>(cols, get<1>(data))); // Sets the new matrix size and fills with n

    cout << "\nFile size: " << size << "\nRows: " << rows << "\nCols: " << cols << "\nn: " << get<1>(data) << "\n\n";

    cout << "ASCII input:" << endl;
    cout << "\t";
    for (auto k : get<0>(data))
        cout << int(k) << " ";

    // Fill matrix with input
    int index = 0; // Index of file input
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (index < size)
            {
                grid[i][j] = int(get<0>(data)[index]);
                index++;
            }
        }
    }

    cout << "\n\nASCII matrix:" << endl;
    for (int i = 0; i < rows; i++)
    {
        cout << "\t";
        for (int j = 0; j < cols; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }

    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            a[i] += grid[j][i];
        }
    }

    cout << "\nArray a: " << endl;
    cout << "\t";
    int aSize = sizeof(a) / sizeof(int);
    for (int i = 0; i < aSize; i++)
    {
        a[i] = a[i] % 256;
        cout << a[i] << " ";
    }

    int s = get<1>(data) / (get<1>(data) / 4);
    int j = 0;
    int g = 0;
    for (int i = 0; i < get<1>(data); i++)
    {
        if (s == j)
        {
            g++;
            j = 0;
        }

        groups[g] += a[i];
        j++;
    }

    cout << "\n\nGroups n/4: " << endl;
    cout << "\t";
    for (auto i : groups)
    {
        cout << i << " ";
    }

    cout << "\n\nGroups n/4 in HEX: " << endl;
    cout << "\t";
    for (auto i : groups)
    {
        cout << toHex(i) << " ";
    }
}

string toHex(int ascii)
{
    /*
    Complejidad:
    - Tiempo: O(N)
    - Espacio: O(N+M)
    */
    string hex;
    char arr[100];
    int i = 0;
    while (ascii != 0)
    {
        int temp = 0;
        temp = ascii % 16;
        if (temp < 10)
        {
            arr[i] = temp + 48;
            i++;
        }
        else
        {
            arr[i] = temp + 55;
            i++;
        }
        ascii = ascii / 16;
    }
    for (int j = i - 1; j >= 0; j--)
    {
        hex += arr[j];
    }

    return hex;
}