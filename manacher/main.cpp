#include <fstream>
#include <iostream>
#include <vector>
#include <string>

std::vector<int> manacher(std::string str);
std::vector<int> manacherP(std::string T);

int main()
{
    std::string str = "ANNA123";
    std::vector<int> m = manacher(str);
}

// First we need to get the string T with hashes between each character of the string

/* std::string removeHashes(std::string T)
{

    std::string tempString = "";

    for (int i = 0; i <= T.length(); i++)
    {
        if (!(T[i] == '#' || T[i] == '@' || T[i] == '$'))
        {
            tempString += T[i];
        }
    }

    return tempString;
} */

std::vector<int> manacher(std::string str)
{
    std::string T;
    for (auto i : str)
        T += std::string("#") + i;

    return manacherP(T + "#");
}

std::vector<int> manacherP(std::string T)
{
    int len = T.length();
    T = "$" + T + "@";
    std::vector<int> P(len + 2); // Length of $ #smth#...#smth# @

    std::cout << "T: " << T << std::endl;

    // c = center, r = right, l = left... Basically
    int c = 1, r = 1; // We need to start at 1

    // T = $#A#B#A#B#A#B#A#@
    // P = 00000000000000000
    // P = 00103050705030100
    for (int i = 1; i < len; i++)
    { // Move over all the string

        int mirr = 2 * c - i;

        if (i < r)
        { // This shit just speeds up the process, so its good for time complexity
            P[i] = std::min(r - i, P[mirr]);
        }

        while (T[i + (1 + P[i])] == T[i - (1 + P[i])])
        { // Move to the previous and next character to see if there are equals, if so, P[i] increases its value
            // std::cout << T[i] <<" Prev: " <<T[i + (1 + P[i])] << " Next: " << T[i - (1 + P[i])] << std::endl;
            P[i]++;
        }

        if (i + P[i] > r)
        {                 // If the new Right is greater than the accumulated R
            c = i;        // Move to new center
            r = i + P[i]; // Move to new right
        }
    }

    std::cout << "P: ";
    for (int i = 0; i < P.size(); i++)
        std::cout << P[i];

    // std::cout << "\nCenter: " << T[c] << " Right: " << T[r] << std::endl;

    // std::cout << removeHashes(T);

    return P;
}
