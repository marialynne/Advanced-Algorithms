#include <unordered_map>
#include <string>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

// Nodes
class TrieNode
{
public:
    std::unordered_map<char, TrieNode *> children;
};
// Trie
class SuffixTrie
{
public:
    TrieNode *root;
    char endSymbol;

    SuffixTrie() // Constructor std::string str
    {
        this->root = new TrieNode();
        this->endSymbol = '*';
        // this->populateSuffixTrieFrom(str);
    }

    void insertSubstringStartingAt(int index, std::string str)
    {
        auto node = this->root;
        std::cout << index << " " << str << std::endl;

        for (int i = index; i < str.length(); i++)
        {
            char letter = str[i];
            // std::cout << letter << std::endl;
            // std::cout << !(node->children[index]) << std::endl;
            if (!(node->children[index]))
            {
                node->children[index] = {};
            }

            node = node->children[index];
        }
        std::cout << node[this->endSymbol].children[index];
    }

    void populateSuffixTrieFrom(std::string str)
    {
        for (int i = 0; i < str.length(); i++)
            this->insertSubstringStartingAt(i, str);
    }

    bool contains(std::string str)
    {
        // Write your code here.

        return false;
    }
};

int main()
{
    std::vector<std::string> dictionary = {"hola", "mundo", "persona", "pasajero", "lechuga"};
    SuffixTrie myTrie;
    for (auto i : dictionary)
        myTrie.populateSuffixTrieFrom(i);

    return 0;
}
