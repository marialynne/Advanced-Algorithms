#include <bits/stdc++.h>
using namespace std;

void printGrid(vector<vector<char>> grid);

int main()
{

    return 0;
}

void printGrid(vector<vector<char>> grid)
{
    int i, j;
    int rows = grid.size();
    int cols = grid[0].size();

    for (i = 0; i < rows; i++)
    {
        cout << "\t";
        for (j = 0; j < cols; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
}