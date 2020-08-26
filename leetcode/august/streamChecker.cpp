#include <vector>
#include <string>
#include <iostream>


using namespace std;

class Trie
{
public:
    Trie()
    {
        this->is_leaf = false;
        for (int i = 0; i < 26; i++) { this->children[i] = NULL; }
    }

    void insert_reversed(string word)
    {
        reverse(word.begin(), word.end());
        Trie *root = this;
        for (char ch : word)
        {
            int index = ch - 'a';
            if (root->children[index] == NULL) { root->children[index] = new Trie(); }
            root = root->children[index];
        }
        root->is_leaf = true;
    }

    bool is_leaf;
    Trie *children[26];
};

class StreamChecker
{
private:
    Trie trie;
    vector<char> queries;
    int longest_word = 0;
public:
    StreamChecker(vector<string> &words)
    {
        // insert reversed word into trie and keep track of the length of longest word
        for (auto &word: words)
        {
            trie.insert_reversed(word);
            if (word.length() > longest_word) { longest_word = word.length(); }
        }
    }

    bool query(char letter)
    {
        queries.insert(queries.begin(), letter);
        // keep in queries only the "longest word" last queries, because we don't need the other ones anymore
        if (queries.size() > longest_word) { queries.pop_back(); }
        Trie *cur = &trie;
        for (char &query : queries)
        {
            if (cur->is_leaf) return true;
            if (cur->children[query - 'a'] == NULL) return false;
            cur = cur->children[query - 'a'];
        }
        return cur->is_leaf;
    }
};