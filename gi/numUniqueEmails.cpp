//
// Created by Михаил Степанов on 03.08.2020.
//

#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int _numUniqueEmails(const vector<string> &emails) {
        unordered_set<string> outputSet;
        for (const string &email: emails) {
            string buf;
            bool skipTilAt = false;
            bool inDomain = false;
            for (char ch: email) {
                if (ch == '.' && !inDomain) {
                    continue;
                }
                if (!inDomain && ch == '+') {
                    skipTilAt = true;
                    continue;
                }
                if (inDomain) {
                    buf.append(1, ch);
                    continue;
                }
                if (ch == '@') {
                    inDomain = true;
                    buf.append(1, ch);
                    continue;
                }
                if (!skipTilAt) {
                    buf.append(1, ch);
                }
            }
            outputSet.insert(buf);
        }
        return outputSet.size();
    }

    int numUniqueEmailsNotMine(const vector<string> &emails) {
        unordered_set<string> ust;

        for (auto str:emails) {
            string tmp;

            for (auto c:str) {
                if (c == '.') continue;
                if (c == '+' || c == '@') break;
                tmp.push_back(c);
            }
            ust.insert(tmp + str.substr(str.find('@')));
        }

        return ust.size();
    }

    int numUniqueEmails(const vector<string> &emails) {
        // Memory inefficient, slow?
        unordered_set<string> ust;

        for (auto str:emails) {
            string tmp;

            int i;
            for (i = 0; i < str.size(); i++) {
                if (str[i] == '.') continue;
                if (str[i] == '+' || str[i] == '@') break;
                tmp.append(1, str[i]);
            }
            if (str[i] == '+') {
                for (; i < str.size(); i++) {
                    if (str[i] == '@') break;
                }
            }
            for (; i < str.size(); i++) tmp.append(1, str[i]);
            // ust.insert(tmp + str.substr(str.find('@')));
            ust.insert(tmp);
        }

        return ust.size();
    }
};


int main() {
    Solution solution;
    cout << (solution.numUniqueEmails(
            {"test.email+alex@leetcode.com", "test.email@leetcode.com"}) == 1)
         << endl;
    cout << (solution.numUniqueEmails(
            {"test.email+alex@leetcode.com",
             "test.e.mail+bob.cathy@leetcode.com",
             "testemail+david@lee.tcode.com"}) == 2)
         << endl;
    cout << (solution.numUniqueEmails(
            {"test.email+alex@leetcode.com", "test.email.leet+alex@code.com"}) == 2)
         << endl;
    return 0;
}