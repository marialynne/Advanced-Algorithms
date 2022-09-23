#include <bits/stdc++.h>
using namespace std;

// Created by Manuel Camacho
void suffixArray(string text);
void print(vector<tuple<string, int>> array);
vector<tuple<string, int>> mergeSort(vector<tuple<string, int>> array);

int main()
{
    string text;
    cout << "\nType your text: ";
    getline(cin, text);
    suffixArray(text);

    return 0;
}

void suffixArray(string text)
{
    // O(N) time | O(N) space
    vector<tuple<string, int>> suffixes;

    int len = text.length();
    for (int i = 0; i < len; i++)
    {
        suffixes.push_back(tuple<string, int>(text, i + 1));
        text.erase(text.begin());
    }
    cout << "\nSuffixes:\n";
    print(suffixes);
    // Forma fácil <3
    // sort(suffixes.begin(), suffixes.end());
    // print(suffixes);

    // Con un método de ordenamiento >:(
    cout << "Ordered suffixes:\n";
    print(mergeSort(suffixes));
}

void print(vector<tuple<string, int>> array)
{
    // O(N) time | O(N) space
    for (auto i : array)
        cout << get<1>(i) << ") " << get<0>(i) << endl;
    cout << endl;
}

vector<tuple<string, int>> mergeSort(vector<tuple<string, int>> array)
{
    // O(N log(N)) time | O(N) space

    if (array.size() <= 1)
        return array; // Return array with one element

    /*
        Middle of array
        Right part of the array
        Left part of the array
    */
    int mid = array.size() / 2;
    vector<tuple<string, int>> left;
    vector<tuple<string, int>> right;
    copy(array.begin(), array.begin() + mid, back_inserter(left));
    copy(array.begin() + mid, array.end(), back_inserter(right));

    // Devide
    left = mergeSort(left);   // Merge each half left
    right = mergeSort(right); // Merge each hlaf right

    vector<tuple<string, int>> ans; // Resulting array
    int i = 0;
    int j = 0;

    // Sort
    while (i < left.size() && j < right.size())
    {
        if (left[i] < right[j])
        {
            ans.push_back(left[i]);
            i++;
        }
        else
        {
            ans.push_back(right[j]);
            j++;
        }
    }

    if (i == left.size())
    {
        i = j;
        left = right;
    }

    while (i < left.size())
    {
        ans.push_back(left[i]);
        i++;
    }
    return ans;
}