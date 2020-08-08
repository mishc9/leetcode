//
// Created by Михаил Степанов on 05.08.2020.
//

#include <iostream>
#include <string>
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
        bool wasInserted = false;
        for (char i : word) {
            wasInserted = false;
            if (node->children.count(i) == 0) {
                auto newNode = new WordDictionary(false);
                node->children[i] = newNode;
                wasInserted = true;
            }
            node = node->children.at(i);
        }
        node->endNode = true;
        if (wasInserted) { size++; }
    }


    bool search(const string &word) {
        return searchHelper(word, 0);
    }

    int getSize() {
        return size;
    }


private:
    bool endNode = true;
    int size = 0;
    unordered_map<char, WordDictionary *> children;

    bool searchHelper(const string &word, int pos) {
        if (pos == word.size()) { return endNode; }
        char c = word[pos];
        if (c == '.') {
            // wildcard case
            for (auto[k, v]: children) { if (children.at(k)->searchHelper(word, pos + 1)) { return true; }}
        } else if (children.count(c) != 0) { return children.at(c)->searchHelper(word, pos + 1); }
        return false;
    }
};

class Solution {
public:
    int numUniqueEmails(const vector<string> &emails) {
        auto *wordDictionary = new WordDictionary();
        for (const string &email : emails) { wordDictionary->addWord(cleanEmail(email)); }
        return wordDictionary->getSize();
    }

// private:
    string cleanEmail(const string &email) {
        string buf;
        int i;
        for (i = 0; i < email.size(); i++) {
            char c = email[i];
            if (c == '+' || c == '@') { break; }
            if (c == '.') { continue; }
            buf.append(1, c);
        }
        for (; i < email.size() && email[i] != '@'; i++) {}
        for (; i < email.size(); i++) { buf.append(1, email[i]); }
        return buf;
    }
};


int main() {
    Solution solution;
    cout << solution.cleanEmail("test.email+alex@leetcode.com") << endl;
    cout << solution.cleanEmail("test.e.mail+bob.cathy@leetcode.com") << endl;
    cout << solution.cleanEmail("testemail+david@lee.tcode.com") << endl;
    cout << solution.cleanEmail("test.email+alex@leetcode.com") << endl;
    cout << solution.cleanEmail("test.email@leetcode.com") << endl;
    cout << solution.numUniqueEmails(
            {"test.email+alex@leetcode.com", "test.e.mail+bob.cathy@leetcode.com", "testemail+david@lee.tcode.com"})
         << endl;
    cout << solution.numUniqueEmails(
            {"test.email+alex@leetcode.com", "test.email@leetcode.com"}) << endl;
    return 0;
}