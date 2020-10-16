//
// Created by Михаил Степанов on 11.10.2020.
//

#include <set>
#include <string>
#include <unordered_map>
#include <vector>
#include <stack>
#include <deque>
#include <unordered_set>

using namespace std;

class _Solution
{
public:
    static string removeDuplicateLetters(const string &s)
    {

        deque<char> stack;

        // this lets us keep track of what's in our solution in O(1) time
        unordered_set<char> seen;

        // this will let us know if there are any more instances of s[i] left in s
        unordered_map<char, int> lastOccurrence;
        for (int i = 0; i < s.length(); i++) { lastOccurrence[s[i]] = i; }

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            // we can only try to add c if it's not already in our solution
            // this is to maintain only one of each character
            if (seen.count(c) == 0) {
                // if the last letter in our solution:
                //     1. exists
                //     2. is greater than c so removing it will make the string smaller
                //     3. it's not the last occurrence
                // we remove it from the solution to keep the solution optimal
                while (!stack.empty() && c < stack.back() && lastOccurrence[stack.back()] > i) {
                    char value = stack.back();
                    seen.erase(value);
                    stack.pop_back();
                }
                seen.insert(c);
                stack.push_back(c);
            }
        }
        string answer;
        while (!stack.empty()) {
            answer.append(1, stack.front());
            stack.pop_front();
        }
        return answer;
    }
};

class Solution
{
public:
    static string removeDuplicateLetters(const string &s)
    {

        deque<char> stack;
        unordered_set<char> seen;
        unordered_map<char, int> lastOccurrence;
        for (int i = 0; i < s.length(); i++) { lastOccurrence[s[i]] = i; }

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (seen.count(c) == 0) {
                while (!stack.empty() && c < stack.back() && lastOccurrence[stack.back()] > i) {
                    char value = stack.back();
                    seen.erase(value);
                    stack.pop_back();
                }
                seen.insert(c);
                stack.push_back(c);
            }
        }
        string answer;
        while (!stack.empty()) {
            answer.append(1, stack.front());
            stack.pop_front();
        }
        return answer;
    }
};

#include <iostream>

int main()
{
    cout << Solution::removeDuplicateLetters("bcabc") << " abc" << endl;
    cout << Solution::removeDuplicateLetters("cbacdcbc") << " acdb" << endl;
    return 0;
}

