#include<bits/stdc++.h>
using namespace std;

int getNumberOfAttackingQueenPlacements(int row, vector<int> columnPlacements, int boardSize);
bool isNonAttackingPlacement(int row, int col, vector<int> columnPlacements);
int nonAttackingQueens(int n);
void printBoard(vector<vector<int>> &board);
vector<vector<int>> board(5, vector<int> (5, 0));

int main() 
{
    int n = 4;
    cout << "\n";
    cout << nonAttackingQueens(n);
    cout << "\n";
    //printBoard(board);
}

void printBoard(vector<vector<int>> &board)
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

int nonAttackingQueens(int n) 
{
  vector<int> columnPlacements(n,0);
  return getNumberOfAttackingQueenPlacements(0, columnPlacements, n);
}

int getNumberOfAttackingQueenPlacements(int row, vector<int> columnPlacements, int boardSize)
{
    if(row == boardSize)
        return 1;
    
    int validPlacements = 0;

    for(int col=0; col < boardSize; col++)
    {
        if(isNonAttackingPlacement(row, col, columnPlacements))
        {
            
            columnPlacements[row] = col;


            if(row == 4)
            {
                for(int i = 0; i < boardSize; i++)
                {
                    cout << columnPlacements[i] << " ";
                }
                cout << "\t" << validPlacements << endl;
            }
            
            validPlacements += getNumberOfAttackingQueenPlacements(row + 1, columnPlacements, boardSize);
        }
    }
    return validPlacements;
}

bool isNonAttackingPlacement(int row, int col, vector<int> columnPlacements)
{
    int previousRow, columToCheck, sameColum, onDiagonal;

    for(previousRow=0; previousRow < row; previousRow++)
    {
        columToCheck = columnPlacements[previousRow];
        sameColum = columToCheck == col;
        onDiagonal = abs(columToCheck - col) == row - previousRow;

        if (sameColum || onDiagonal)
            return false;
    }   
    return true;
}