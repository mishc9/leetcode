//
// Created by Михаил Степанов on 29.09.2020.
//

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    static bool wordBreak(const string &s, const vector<string> &wordDict)
    {
        int start = 0;
        queue<int> q;
        q.push(start);
        unordered_set<string> words;
        vector<bool> visited(s.size(), false);
        for (auto &word: wordDict) { words.insert(word); }

        while (!q.empty()) {
            start = q.front();
            q.pop();
            if (!visited[start]) {
                for (int end = start + 1; end <= s.size(); end++) {
                    string substr = s.substr(start, end - start);
                    if (words.count(substr) != 0) {
                        q.push(end);
                        if (end == s.size()) { return true; }
                    }
                }
                visited[start] = true;
            }
        }
        return false;
    }

    static bool DPWordBreak(const string &s, const vector<string> &wordDict)
    {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        unordered_set<string> words;
        for (auto &word: wordDict) { words.insert(word); }
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && words.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }

};

int main()
{
    cout << Solution::wordBreak("applepenapple", {"apple", "pen"}) << endl;
    cout << Solution::wordBreak("catsandog", {"cats", "dog", "sand", "and", "cat"}) << endl;
    cout << Solution::wordBreak("leetcode", {"leet", "code"}) << endl;
    cout << "-------" << endl;
    cout << Solution::DPWordBreak("applepenapple", {"apple", "pen"}) << endl;
    cout << Solution::DPWordBreak("catsandog", {"cats", "dog", "sand", "and", "cat"}) << endl;
    cout << Solution::DPWordBreak("leetcode", {"leet", "code"}) << endl;
    return 0;
}