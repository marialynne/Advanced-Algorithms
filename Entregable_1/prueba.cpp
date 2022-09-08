#include <iostream>
 
using namespace std;
 
string X, Y;
int f, s;

int lcs(int i, int j, int count, int first, int second)
{
    if (i == 0 || j == 0) return count;
 
    if (X[i - 1] == Y[j - 1]) count = lcs(i - 1, j - 1, count + 1);

    return max(count, max(lcs(i, j - 1, 0), lcs(i - 1, j, 0)));
}
// Driver code
int main()
{
    int n, m;
 
    X = "holaa xd sd";
    Y = "ho dsds ho ho";
 
    n = X.size();
    m = Y.size();
 
    cout << lcs(n, m, 0, 0, 0);
 
    return 0;
}