//
// Created by Михаил Степанов on 19.08.2020.
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <sstream>

using namespace std;

class _Solution {
    const unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u',
                                     'A', 'E', 'I', 'O', 'U'};

public:
    string toGoatLatin(const string &S) {
        string ans, tok, suff;
        istringstream ss(S);
        while (ss >> tok) {
            suff += 'a';
            if (vowels.count(tok[0]) <= 0) { tok = tok.substr(1) + tok[0]; }
            ans += tok + "ma" + suff + ' ';
        }
        ans.pop_back();    // remove extra space
        return ans;
    }
};


class Solution {
    const unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u',
                                     'A', 'E', 'I', 'O', 'U'};
public:
    string toGoatLatin(string engString) {
        if (engString.empty()) { return engString; }
        int wordCount = countWords(engString);
        extendString(engString, wordCount);
        toGoatLatinHelper(engString);
        return engString;
    }

protected:
    inline int countWords(const string &engString) {
        if (engString.empty()) { return 0; }
        int count = 1;
        for (auto c: engString) { if (c == ' ') { count++; }}
        return count;
    }

    inline void extendString(string &engString, int numWords) {
        int extSize = 2 * numWords + (numWords * (numWords + 1)) / 2;
        engString.append(extSize, ' ');
    }

    inline void toGoatLatinHelper(string &engString) {
        int insertTo = 0;
        int endWordPointer = 0;

        for (int pickFrom = 0; pickFrom < engString.size();) {
            while (engString[endWordPointer] != ' ') { endWordPointer++; };
            if (vowels.count(engString[pickFrom]) != 0) {

            } else {

            }
        }
    }
};


struct Case {
    string input;
    string result;
    string description;
};

bool runTests(const vector<Case> &testCases) {
    _Solution solution;
    bool hasPassed = true;
    for (auto &case_: testCases) {
        string result = solution.toGoatLatin(case_.input);
        hasPassed = hasPassed & (result == case_.result);
        string success = (result == case_.result) ? "passes" : "failed";
        cout << "Test " << case_.description
             << ": for input '" << case_.input << "' expected output is '" << case_.result
             << "'; received '" << result << "'; test has " << success << endl;

    }
    return hasPassed;
}

int main() {
    vector<Case> cases{
            {"I speak Goat Latin", "Imaa peaksmaaa oatGmaaaa atinLmaaaaa", "case1"},
            {"The quick brown fox jumped over the lazy dog",
                                   "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa",
                                                                           "case2"},
    };
    bool allPassed = runTests(cases);
    cout << "Tests: " << (allPassed ? "passed" : "failed") << endl;
    return 0;
}