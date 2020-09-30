//
// Created by Михаил Степанов on 30.09.2020.
//

#include <vector>
#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    static bool wordBreak(const string &phrase, const vector<string> &dictionary)
    {
        if (phrase.empty()) { return false; }
        unordered_set<string> words;
        for (const string &word: dictionary) { words.insert(word); }
        vector<bool> visited(phrase.size(), false);
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int start = q.front();
            q.pop();
            if (!visited[start]) {
                for (int end = start + 1; end <= phrase.size(); end++) {
                    string substr = phrase.substr(start, end - start);
                    if (words.count(substr) != 0) {
                        if (end == phrase.size()) { return true; }
                        else { q.push(end); }
                    }
                }
            }
            visited[start] = true;
        }
        return false;
    }
};

int main()
{
    cout << Solution::wordBreak("leetcode", {"leet", "code"}) << endl;
    cout << Solution::wordBreak("applepenapple", {"pen", "apple"}) << endl;
    cout << Solution::wordBreak("catsandog", {"cat", "cats", "sand", "dog", "and"}) << endl;

    return 0;
}
