#include <bits/stdc++.h>
using namespace std;

void printGrid(vector<vector<int>> grid);
void printSolutions(vector<vector<int>> grid, vector<vector<bool>> visited, int destX, int destY);
bool safeMove(vector<vector<int>> grid, vector<vector<bool>> visited, int x, int y);
vector<vector<int>> moves(vector<vector<int>> &mat, vector<vector<bool>> &visited, int i, int j, int x, int y, int &min_dist, int dist);
void shortPath(vector<vector<int>> &grid, int &x, int &y, int &destX, int &destY);
int z = 0;
int c1 = 0;
int c2 = 0;

int main()
{
    /*
    vector<vector<int>> grid =  {{1,1,1,1,1},
                                {1,1,0,0,1},
                                {1,1,1,1,1},
                                {0,1,0,1,0},
                                {1,1,0,1,1}};
    */
    vector<vector<int>> maze;
    int temp, n, m;
    bool doAction = true;
    bool numbers, strings;

    cout << "M (filas): ";
    cin >> m;
    cout << "\nN (columnas): ";
    cin >> n;
    cout << "\nColocar datos por fila separados por un espacio, ejemplo: 1 1 1 1" << endl;
    cout << "Solo se acpetan 1s y 0s, siendo 1 camino y 0 pared" << endl;
    cout << "\nIntroduzca sus datos a continuación:" << endl;
    for (int i = 0; i < m; i++)
    {

        vector<int> rows;
        for (int j = 0; j < n; j++)
        {
            cin >> temp;
            if (!(temp == 1 || temp == 0) || cin.fail())
                doAction = false;
            rows.push_back(temp);
        }
        maze.push_back(rows);
    }

    int x = 0;
    int y = 0;
    int destX = m - 1;
    int destY = n - 1;

    if (doAction && maze[destX][destY] == 1)
    {
        cout << "\nGrid original:\n"
             << endl;
        printGrid(maze);
        cout << "\nSoluciones:\n"
             << endl;
        shortPath(maze, x, y, destX, destY);
    }
    else
    {
        cout << "[Error] Input invalido :(" << endl;
    }
}

void printGrid(vector<vector<int>> grid)
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

void printSolutions(vector<vector<int>> grid, vector<vector<bool>> visited, int destX, int destY)
{
    int i, j;
    int rows = grid.size();
    int cols = grid[0].size();

    grid[destX][destY] = 2;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            if (visited[i][j] == 1)
                grid[i][j] = 2;
        }
    }
    printGrid(grid);
    cout << endl;
}

bool safeMove(vector<vector<int>> grid, vector<vector<bool>> visited, int x, int y)
{
    return (x >= 0 && x < grid.size()) &&     // X
           (y >= 0 && y < grid[0].size()) &&  // Y
           grid[x][y] == 1 && !visited[x][y]; // Grid
}

vector<vector<int>> moves(vector<vector<int>> &grid, vector<vector<bool>> &visited, int x, int y, int destX, int destY, int &min_dist, int dist)
{
    if (x == destX && y == destY)
    {
        min_dist = min(dist, min_dist);
        if (min_dist == dist)
        {
            if (z == 0)
            {
                cout << "Ramificación y poda:" << endl;
                cout << "\tPasos dados para encontrar el camino: " << c1 << endl;
                printSolutions(grid, visited, destX, destY);
                cout << "Solicion(es) backtracking: " << endl;
            }
            cout << "\tPasos dados para encontrar el camino: " << c2 << endl;
            printSolutions(grid, visited, destX, destY);
            z += 1;
        }
    }

    visited[x][y] = true;
    c1++;
    c2++;
    if (safeMove(grid, visited, x + 1, y))
        grid = moves(grid, visited, x + 1, y, destX, destY, min_dist, dist + 1);
    if (safeMove(grid, visited, x, y + 1))
        grid = moves(grid, visited, x, y + 1, destX, destY, min_dist, dist + 1); // c1++; c2++;
    if (safeMove(grid, visited, x - 1, y))
        grid = moves(grid, visited, x - 1, y, destX, destY, min_dist, dist + 1); // c1++; c2++;
    if (safeMove(grid, visited, x, y - 1))
        grid = moves(grid, visited, x, y - 1, destX, destY, min_dist, dist + 1); // c1++; c2++;

    visited[x][y] = false;
    return grid;
}

void shortPath(vector<vector<int>> &grid, int &x, int &y, int &destX, int &destY)
{
    if (grid.size() == 0 || grid[x][y] == 0 || grid[destX][destY] == 0)
        return;

    int rows = grid.size();
    int cols = grid[0].size();
    int min_dist;

    vector<vector<bool>> visited;
    visited.resize(rows, vector<bool>(cols));

    grid = moves(grid, visited, x, y, destX, destY, min_dist, 0);
}