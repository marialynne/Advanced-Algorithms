#include<bits/stdc++.h>
using namespace std;

int optimeze(int i, int j, int k);
vector<vector<int>> dfs(int d, int s, int i, vector<int> c, const vector<int> v, vector<int> time, int opt, int k, vector<vector<int>> &combinations);
void printGrid(vector<vector<int>> grid);
vector<int> res;

int main()
{
    vector<int> time = {6,12,4};
    vector<int> client = {1,2,3};
    int opt = 0;
    int k = 0;
    vector<vector<int>> combinations;

    vector<int> c;
    const int length = 3;
    combinations = dfs(0, length, -1, c, client, time, opt, k, combinations);
    cout << "\nOptimo = " << *min_element(res.begin(), res.end()) << endl;

    printGrid(combinations);
}


int accumulation(vector<vector<int>> combinations, vector<int> time) 
{

}


int optimeze(int i, int j, int k)
{
    return i + (i+ j) + (i+ j+ k);;
}

void printGrid(vector<vector<int>> grid) 
{
    int i, j;
    int rows = grid.size();
    int cols = grid[0].size();

    for(i=0; i<rows; i++) 
    {
        cout << "\t";
        for(j=0; j<cols; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    } 
}

vector<vector<int>> dfs(int d, int s, int i, vector<int> c, const vector<int> v, vector<int> time, int opt, int k, vector<vector<int>> &combinations)
{

    //cout << d << " " << s << endl;
    if (d == s)
    {
        do
        {
            combinations.push_back(vector<int>());
            
            for (int i = 0; i < c.size(); i++) {
                combinations[k].push_back(c[i]);
            }
            k+=1;
            cout << "\t";
            
            int i = time[c[0]-1], j = time[c[1]-1], k = time[c[2]-1];
    
            cout << "\t" << optimeze(i, j, k);
            res.push_back(optimeze(i, j, k));
            
            cout << " \t"<<endl;
            
            //printGrid(combinations);

        }
        while (next_permutation(c.begin(), c.end()));
    }

    for (int j = i + 1; j < (int)v.size(); ++j)
    {
        c.push_back(v[j]);
        combinations = dfs(d + 1, s, j, c, v, time, opt, k, combinations);
        c.pop_back();
    }

    return combinations;
}
