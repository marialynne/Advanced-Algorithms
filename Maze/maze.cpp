#include<bits/stdc++.h>
using namespace std;

void printGrid( vector<vector<int>> grid );
bool safeMove( vector<vector<int>> grid, vector<vector<bool>> visited, int x, int y );
vector<vector<int>> shortestPath( vector<vector<int>> grid, vector<vector<bool>> visited, pair<int, int> src, pair<int, int> dest, int min_dist, int dist );

int main()
{
    pair<int, int> src = make_pair(0, 0); // Source
    pair<int, int> dest = make_pair(4, 4); // Destiny
    vector<vector<int>> grid = {{1,1,1,1,1},
                                {1,1,0,0,1},
                                {1,1,1,1,1},
                                {0,1,0,1,0},
                                {1,1,0,1,1}};
    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<bool>> visited;
    visited.resize(rows, vector<bool>(cols));

    cout << "Maze before tracking:" << endl;
    printGrid( grid );
    cout << "\nMaze after tracking:" << endl;
    grid = shortestPath( grid, visited, src, dest, 0, 0 ); 
    printGrid( grid );
}

void printGrid( vector<vector<int>> grid ) 
{
    int i, j;
    int rows = grid.size();
    int cols = grid[0].size();

    for(i=0; i<rows; i++) 
    {
        for(j=0; j<cols; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    } 
}

void printGridBool( vector<vector<bool>> grid ) 
{
    int i, j;
    int rows = grid.size();
    int cols = grid[0].size();

    for(i=0; i<rows; i++) 
    {
        for(j=0; j<cols; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    } 
}

bool safeMove( vector<vector<int>> grid, vector<vector<bool>> visited, int x, int y ) 
{
    return (x >= 0 && x < grid.size()) && 
            (y >= 0 && y < grid[0].size()) &&
			grid[x][y] == 1 && !visited[x][y];
}

vector<vector<int>> shortestPath( vector<vector<int>> grid, vector<vector<bool>> visited, pair<int, int> src, pair<int, int> dest, int min_dist, int dist )
{
    int x = src.first;
    int y = src.second;

    visited[y][x] = true;
    grid[y][x] = 2;

    // Bottom
    if(safeMove( grid, visited, x, y + 1)) 
    {
        src.second = y + 1;
        grid = shortestPath( grid, visited, src, dest, min_dist, dist + 1);
    } 
    // Up
    if(safeMove( grid, visited, x, y - 1)) 
    {
        src.second = y - 1;
        grid = shortestPath( grid, visited, src, dest, min_dist, dist + 1);
    } 
    // Right
    if(safeMove( grid, visited, x + 1, y)) 
    {
        src.first = x + 1;
        grid = shortestPath( grid, visited, src, dest, min_dist, dist + 1);
    }  
    // Left
    if(safeMove( grid, visited, x - 1, y)) 
    {
        src.first = x - 1;
        grid = shortestPath( grid, visited, src, dest, min_dist, dist + 1);
    } 
    visited[x][y] = false;

    min_dist = min(dist, min_dist);
    return grid;
}



