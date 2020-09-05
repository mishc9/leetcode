#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

template<typename T>
ostream &operator<<(ostream &os, const vector<T> &vec)
{
    os << "[";
    bool firstStep = true;

    for (const auto &val: vec) {
        if (firstStep) {
            os << val;
            firstStep = false;
            continue;
        }
        os << ", " << val;
    }

    os << "];";
    return os;
}


class Solution
{
public:
    bool repeatedSubstringPattern(const string &s)
    {
        int n = s.length();
        vector<int> dynamic_programming(n, 0);
        // Construct partial match table (lookup table).
        // It stores the length of the proper prefix that is also a proper suffix.
        // ex. ababa --> [0, 0, 1, 2, 1]
        // ab --> the length of common prefix / suffix = 0
        // aba --> the length of common prefix / suffix = 1
        // abab --> the length of common prefix / suffix = 2
        // ababa --> the length of common prefix / suffix = 1
        for (int i = 1; i < n; ++i) {
            int j = dynamic_programming[i - 1];
            while (j > 0 && s[i] != s[j]) { j = dynamic_programming[j - 1]; }
            if (s[i] == s[j]) { ++j; }
            dynamic_programming[i] = j;
        }

        int l = dynamic_programming[n - 1];
        // check if it's repeated pattern string
        return l != 0 && l % (n - l) == 0;
    }
};


int main()
{
    Solution solution;
    cout << (solution.repeatedSubstringPattern("abcababcab") == 1) << endl;
    cout << (solution.repeatedSubstringPattern("aba") == 0) << endl;
    cout << (solution.repeatedSubstringPattern("abab") == 1) << endl;
    cout << (solution.repeatedSubstringPattern("abcabcabcabc") == 1) << endl;
    cout << (solution.repeatedSubstringPattern("abcababcaba") == 0) << endl;
    cout << (solution.repeatedSubstringPattern("abaababaab") == 1) << endl;
    return 0;
}

