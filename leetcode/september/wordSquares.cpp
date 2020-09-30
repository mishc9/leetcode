//
// Created by Михаил Степанов on 29.09.2020.
//

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution
{
public:
    unordered_map<string, vector<string>> prefixMap;

    vector<vector<string>> wordSquares(vector<string> &words)
    {
        storePrefixWords(words);
        vector<vector<string>> result;

        for (auto &word: words) {
            vector<string> ls;
            ls.push_back(word);
            backTrack(1, ls, result);
        }
        return result;
    }

    void backTrack(int level, vector<string> &ls, vector<vector<string>> &result)
    {
        if (level == ls[0].size()) {
            result.push_back(ls);
            return;
        }
        string prefix;
        for (auto word: ls) {
            prefix = prefix + word[level];
        }

        vector<string> prefixWords;
        prefixWords = prefixMap[prefix];
        for (auto &word: prefixWords) {
            ls.push_back(word);
            backTrack(level + 1, ls, result);
            ls.pop_back();
        }
    }

    void storePrefixWords(vector<string> words)
    {
        for (auto &word : words) {
            for (int i = 1; i <= word.size(); i++) {
                string prefix = word.substr(0, i);
                prefixMap[prefix].push_back(word);
            }
        }
    }
};


// Fixme: requires debug, gives partial answers,
//  ["abat","baba","atan","atal"] -> [["baba","abat","baba","atan"]] instead of
//  [["baba","abat","baba","atal"],["baba","abat","baba","atan"]]
class _Solution
{
    int word_size;
    vector<string> words;
    unordered_map<string, vector<string>> prefixHashTable;
public:
    vector<vector<string>> wordSquares(const vector<string> &words)
    {
        this->words = words;
        this->word_size = words[0].size();
        prefixHashTable.clear();

        vector<vector<string>> results;
        buildPrefixHashTable(words);

        for (auto &word: words) {
            vector<string> wordSquares;
            wordSquares.emplace_back(word);
            backtracking(1, wordSquares, results);
        }
        return results;
    }

    void backtracking(int step,
                      vector<string> &wordSquares,
                      vector<vector<string>> &results)
    {
        if (step == word_size) {
            vector<string> clone(wordSquares);
            results.emplace_back(clone);
            return;
        }

        string prefix;

        for (auto &word: wordSquares) {
            prefix.append(1, word[step]);
        }

        for (string &candidate: getWordsWithPrefix(prefix)) {
            wordSquares.emplace_back(candidate);
            backtracking(step + 1, wordSquares, results);
            wordSquares.pop_back();
        }
    }

    void buildPrefixHashTable(const vector<string> &words)
    {
        for (const string &word: words) {
            for (int i = 1; i < word_size; ++i) {
                string prefix = word.substr(0, i);
                vector<string> wordVector = prefixHashTable[prefix];
                if (wordVector.empty()) {
                    wordVector = {word};
                    prefixHashTable[prefix] = wordVector;
                } else {
                    wordVector.emplace_back(word);
                }
            }
        }
    }

    vector<string> getWordsWithPrefix(const string &prefix)
    {
        if (prefixHashTable.count(prefix) != 0) {
            return prefixHashTable.at(prefix);
        } else {
            return {};
        }
    }
};

int main()
{
    Solution solution;
    cout << solution.wordSquares({"abat", "baba", "atan", "atal"}).size() << endl;
    cout << solution.wordSquares({"area", "lead", "wall", "lady", "ball"}).size() << endl;
    return 0;
}
