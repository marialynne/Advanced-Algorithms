#include <unordered_map>
#include <string>
using namespace std;

// Do not edit the class below except for the
// populateSuffixTrieFrom and contains methods.
// Feel free to add new properties and methods
// to the class.
class TrieNode
{
public:
    unordered_map<char, TrieNode *> children;
};

class SuffixTrie
{
public:
    TrieNode *root;
    char endSymbol;

    SuffixTrie(string str)
    {
        this->root = new TrieNode();
        this->endSymbol = '*';
        this->populateSuffixTrieFrom(str);
    }

    void populateSuffixTrieFrom(string str)
    {
        // Write your code here.
    }

    bool contains(string str)
    {
        // Write your code here.
        return false;
    }
};