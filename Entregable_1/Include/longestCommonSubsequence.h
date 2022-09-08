#include <vector>
#include <utility>
using namespace std;

vector<char> longestCommonSubsequence(string str1, string str2) 
{
    vector<vector<vector<char>>> lcs(str1.size()+1, vector<vector<char>>(str2.size()+1));

    for(size_t i = 1; i < lcs.size(); i++)
    {
        for(size_t j = 1; j < lcs[0].size(); j++)
        {
            if(str1[i-1] == str2[j-1])
            {   
                lcs[i][j] = lcs[i-1][j-1];
                lcs[i][j].push_back(str1[i-1]);
            }
            else
            {
                lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1], [](const auto& lcs1, const auto& lcs2) { return lcs1.size() < lcs2.size(); });
            }
        }
    }

    return lcs[str1.size()][str2.size()];
}

