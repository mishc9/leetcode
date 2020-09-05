//
// Created by Михаил Степанов on 03.09.2020.
//

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
        bool result = false;
        unordered_map<char, int> previouslySeen;
        vector<int> distances;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (previouslySeen.count(c) == 0) {
                distances.emplace_back(0);
                previouslySeen[c] = i;
            } else {
                distances.emplace_back(i - previouslySeen.at(c));
                previouslySeen[c] = i;
            }
        }
        cout << distances << endl;
        return result;
    }
};


int main()
{
    Solution solution;
    // solution.repeatedSubstringPattern("abcababcab");
    return 0;
}