//
// Created by Михаил Степанов on 22.03.2020.

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindromeNaive(string s) {
        int pal_length = 0;
        string longest_pal;
        if (s.empty()) { return s; }
        if (s.size() == 1) { return s; }
        for (int i = 0; i < s.size(); ++i) {
            for (int j = i; j <= s.size(); ++j) {
                if (isPalindrome(s, i, j)) {
                    if ((j - i) > pal_length) {
                        pal_length = j - i;
                        longest_pal = s.substr(i, pal_length);
                    }
                }
            }
        }
        return longest_pal;
    }

    static bool isPalindrome(const string &s, int begin, int end) {
        for (int i = 0; i < (end - begin) / 2; ++i) {
            if (s[begin + i] != s[end - i - 1]) {
                return false;
            }
        }
        return true;
    }

    static string addBoundaries(const string &cs) {
        if (cs.empty()) {
            return "||";
        }

        string cs2(cs.size() * 2 + 1, '|');
        for (int i = 0; i < (cs2.size() - 1); i = i + 2) {
            cs2[i] = '|';
            cs2[i + 1] = cs[i / 2];
        }
        cs2[cs2.size() - 1] = '|';
        return cs2;
    }

    string longestPalindrome(string s) {
        if (s.empty()) {
            return "";
        }

        string s2 = addBoundaries(s);
        vector<int> p(s2.size());
        int c = 0, r = 0; // Here the first element in s2 has been processed.
        int m = 0, n = 0; // The walking indices to compare if two elements are the same
        for (int i = 1; i < s2.size(); i++) {
            if (i > r) {
                p[i] = 0;
                m = i - 1;
                n = i + 1;
            } else {
                int i2 = c * 2 - i;
                if (p[i2] < (r - i)) {
                    p[i] = p[i2];
                    m = -1; // This signals bypassing the while loop below.
                } else {
                    p[i] = r - i;
                    n = r + 1;
                    m = i * 2 - n;
                }
            }
            while (m >= 0 && n < s2.size() && s2[m] == s2[n]) {
                p[i]++;
                m--;
                n++;
            }
            if ((i + p[i]) > r) {
                c = i;
                r = i + p[i];
            }
        }
        int len = 0;
        c = 0;
        for (int i = 1; i < s2.size(); i++) {
            if (len < p[i]) {
                len = p[i];
                c = i;
            }
        }
        string ss = s2.substr(c - len, 2 * len + 1);
        return removeBoundaries(ss);
    }

    static string removeBoundaries(const string &cs) {
        if (cs.empty() || cs.size() < 3)
            return "";

        string cs2((cs.size() - 1) / 2, ' ');
        for (int i = 0; i < cs2.size(); i++) {
            cs2[i] = cs[i * 2 + 1];
        }
        return cs2; //.substr(0, (cs.size() - 1) / 2);
    }
};


int main() {
    Solution sol;
    // cout << sol.addBoundaries("aba") << endl;
    cout << sol.longestPalindrome("bb") << endl;
    cout << sol.longestPalindrome("b") << endl;
    cout << sol.longestPalindrome("") << endl;
    // cout << sol.isPalindrome("cbbd", 1, 3) << endl;
    cout << sol.longestPalindrome("aba") << endl;
    cout << sol.longestPalindrome("abb") << endl;
    cout << sol.longestPalindrome("abb") << endl;
    cout << sol.longestPalindrome("abb") << endl;
    cout << sol.longestPalindrome("zazaz") << endl;
    cout << sol.longestPalindrome("aazaz") << endl;
    cout << sol.longestPalindrome("aazaz") << endl;
    cout << sol.longestPalindrome("a") << endl;
    cout << sol.longestPalindrome("") << endl;
    cout << sol.longestPalindrome("aazaz") << endl;

    return 0;
}

