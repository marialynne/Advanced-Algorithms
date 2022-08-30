#include<bits/stdc++.h>
using namespace std;

vector<vector<bool>> makeBoard(int n); 
void printBoard(vector<vector<bool>> &board);
bool outOfBoard(vector<vector<bool>> &board, vector<vector<bool>> &visited, int i, int j);
bool queenInTheMiddle(vector<vector<bool>> &board, int i, int j);
bool safePlace(vector<vector<bool>> &board, vector<vector<bool>> visited, int i, int j, int &iO, int &jO);
void non_attacking_queens(vector<vector<bool>> &board);

int main() 
{
    int n = 4;
    vector<vector<bool>> board;

    board = makeBoard(n);

    printBoard(board);
    
    non_attacking_queens(board);

}

vector<vector<bool>> makeBoard(int n)
{
    int i, j;
    vector<vector<bool>> board;
    board.resize(n, vector<bool>(n));

    for(i = 0; i < n-1; i++)
    {
        for(j = 0; j < n-1; j++)
        {
            board[i][j] = false;
        }
    }
    return board;
}

void printBoard(vector<vector<bool>> &board)
{
    int i, j;
    int rows = board.size();
    int cols = board[0].size();

    for(i=0; i < rows; i++) 
    {
        cout << "\t";
        for(j=0; j < cols; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    } 
}

bool queenInTheMiddle(vector<vector<bool>> &board, int i, int j)
{
    return (board[i][j] == false);  // Board
}

bool outOfBoard(vector<vector<bool>> &board, vector<vector<bool>> &visited, int i, int j) 
{
    return (i >= 0 && i < board.size()) && (j >= 0 && j < board[0].size()) && !visited[i][j];  
}

bool safePlace(vector<vector<bool>> &board, vector<vector<bool>> visited, int i, int j, int &iO, int &jO)
{
    visited[i][j] = true;
    printBoard(visited);
            cout << endl;
    

    // South
    if(outOfBoard(board, visited, i + 1, j))
    {
        i = iO;
        j = jO;
        if(queenInTheMiddle(board, i + 1, j))
        {
            return safePlace(board, visited, i + 1, j, iO, jO);
        }
        else
        {
            return false;
        }

    }
    


    // Southeast
    if(outOfBoard(board, visited, i + 1, j + 1))
    {
        i = iO;
        j = jO;
        if(queenInTheMiddle(board, i + 1, j + 1))
            return safePlace(board, visited, i + 1, j + 1, iO, jO);
        else 
            return false;       
    }


    // East 
    if(outOfBoard(board, visited, i, j + 1))
    {
        i = iO;
        j = jO;
        if(queenInTheMiddle(board, i, j + 1))
            return safePlace(board, visited, i, j + 1, iO, jO);
        else 
            return false;
    }

    // Northwest
    if(outOfBoard(board, visited, i - 1, j + 1))
    {
        if(queenInTheMiddle(board, i - 1, j + 1))
            return safePlace(board, visited, i - 1, j + 1, iO, jO);
        else 
            return false;
    }


    // Northwest
    if(outOfBoard(board, visited, i - 1, j - 1))
    {
        if(queenInTheMiddle(board, i - 1, j - 1))
            return safePlace(board, visited, i - 1, j - 1, iO, jO);
        else 
            return false;
    }


    // West 
    if(outOfBoard(board, visited, i, j - 1))
    {
        if(queenInTheMiddle(board, i, j - 1))
            return safePlace(board, visited, i, j - 1, iO, jO);
        else 
            return false;
     
    }


    // North
    if(outOfBoard(board, visited, i - 1, j))
    {
        if(queenInTheMiddle(board, i - 1, j))
            return safePlace(board, visited, i - 1, j, iO, jO);
        else 
            return false;
    }

    
    // Southwest
    if(outOfBoard(board, visited, i + 1, j - 1))
    {
        if(queenInTheMiddle(board, i + 1, j - 1))
            return safePlace(board, visited, i + 1, j - 1, iO, jO);
        else 
            return false;

    }
  
    
    visited[i][j] = false;


    return true;
}

void non_attacking_queens(vector<vector<bool>> &board)
{
    int n = board.size();
    int i, j;

    vector<vector<bool>> visited;
    visited.resize(n, vector<bool>(n));
    
    for(i=0; i<n; i++) 
    {
        for(j=0; j<n; j++)
        {
            cout << "("<< i << ", "<< j << ")"<< endl;
            if(safePlace(board, visited, i, j, i, j))
                board[i][j] = true;
        }
    }   
    printBoard(board);
}




