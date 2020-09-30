//
// Created by Михаил Степанов on 24.09.2020.
//

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution
{
public:
    static char findTheDifference(const string &s, const string &t)
    {
        unordered_map<char, int> known_char;
        unordered_map<char, int> new_char;

        for (auto ch: s) {
            known_char[ch] += 1;
        }

        for (auto ch: t) {
            new_char[ch] += 1;
        }
        for (auto &iter : new_char) {
            if (known_char[iter.first] != iter.second) { return iter.first; }
        }
        throw runtime_error("No unexpected character");
    }
};

int main()
{
    cout << Solution::findTheDifference("abcd", "abcde") << endl;
    cout << Solution::findTheDifference("a", "aa") << endl;
    return 0;
}

