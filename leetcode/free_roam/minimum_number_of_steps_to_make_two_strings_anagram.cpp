//
// Created by Михаил Степанов on 1/16/21.
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    static int _minSteps(const string &s, const string &t)
    {
        int n_steps = 0;
        vector<int> source_counts(26, 0);

        for (char c: s) { source_counts[c - 'a']++; }
        for (char c: t) { source_counts[c - 'a']--; }
        for (auto cnt: source_counts) { if (cnt > 0) n_steps += cnt; }
        return n_steps;
    }

    static int minSteps(const string &s, const string &t)
    {
        int n_steps = 0;
        unordered_map<char, int> my_chars;

        for (char c: s) { my_chars[c]++; }
        for (char c : t) {

            if (my_chars.find(c) != my_chars.end() && my_chars[c] > 0) { my_chars[c]--; }
            else { n_steps++; }
        }

        return n_steps;
    }
};

int main()
{

    cout << Solution::minSteps("bab", "aba") << " 1" << endl;
    cout << Solution::minSteps("leetcode", "practice") << " 5" << endl;

    return 0;
}
