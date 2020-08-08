//
// Created by Михаил Степанов on 05.08.2020.
//

#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class WordDictionary {
    // Slow, but kinda works. The lesson is: avoid recursion if you can; don't use substr if you can.
    // Todo: speed things up.
public:

    WordDictionary() {}

    WordDictionary(bool _endNode) { endNode = _endNode; }

    void addWord(const string &word) {
        WordDictionary *node = this;
        for (int i = 0; i < word.size(); i++) {
            if (node->children.count(word[i]) == 0) {
                auto newNode = new WordDictionary(false);
                node->children[word[i]] = newNode;
            }
            node = node->children.at(word[i]);
        }
        node->endNode = true;
    }

    bool search(const string &word) {
        return searchHelper(word, 0);
    }

    bool searchHelper(const string &word, int pos) {
        if (pos == word.size()) { return endNode; }
        char c = word[pos];
        if (c == '.') {
            // wildcard case
            for (auto[k, v]: children) { if (children.at(k)->searchHelper(word, pos + 1)) { return true; }}
        } else if (children.count(c) != 0) { return children.at(c)->searchHelper(word, pos + 1); }
        return false;
    }


private:
    bool endNode = true;
    unordered_map<char, WordDictionary *> children;
};

using TestCases = vector<pair<string, bool>>;

bool runTestCases(WordDictionary *wordDictionary, const TestCases &testCases, const string &header) {
    cout << ">> Running test cases for " << header << ":" << endl;
    bool testResult = true;
    for (auto[str, value]: testCases) {
        bool testCaseResult = (wordDictionary->search(str) == value);
        if (!testCaseResult) { testResult = false; }
        cout << str << "\t" << testCaseResult << endl;
    }
    string message = testResult ? "<< success on: " : "<< failed on: ";
    cout << message << header << endl;
    return testResult;
}


int main() {

    auto *wordDictionary = new WordDictionary();
    wordDictionary->addWord("bad");
    wordDictionary->addWord("mad");
    wordDictionary->addWord("dad");
    wordDictionary->addWord("work");
    wordDictionary->addWord("word");

    vector<pair<string, bool>> testCases{
            {".",      false},
            {"",       true},
            {"bad",    true},
            {"dad",    true},
            {"mad",    true},
            {"work",   true},
            {"word",   true},
            {"pad",    false},
            {"worked", false},
            {"madd",   false},
            {".ad",    true},
            {"..d",    true},
            {"b.d",    true},
            {".or.",   true},
            {"...",    true},
            {"wor.",   true},
            {"wo.l",   false},
            {"mad.",   false},
            {"ma..",   false},
            {"m...",   false},
            {"m.d.",   false},
            {"ma",     false},
            {"ba",     false},
            {"da",     false},
    };
    runTestCases(wordDictionary, testCases, "non-empty trie");

    auto *wordDictionaryEmpty = new WordDictionary();

    vector<pair<string, bool>> testCasesEmpty{
            {".",   false},
            {"",    true},
            {"mad", false}
    };
    runTestCases(wordDictionaryEmpty, testCasesEmpty, "empty trie");

    return 0;
}

