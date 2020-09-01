//
// Created by Михаил Степанов on 01.09.2020.
//

// Could be solved like this:
// https://leetcode.com/problems/largest-time-for-given-digits/discuss/200693/JavaPython-3-11-liner-O(64)-w-comment-6-ms
// But it's quite hardcoded

#include <vector>
#include <string>
#include <iostream>
#include <sstream>

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
    vector<vector<int>> combinations;
    vector<int> index;

    struct greater
    {
        template<class T>
        bool operator()(T const &a, T const &b) const { return a > b; }
    };

public:
    string largestTimeFromDigits(const vector<int> &digits)
    {
        combinations.clear();
        index.clear();
        for (int i = 0; i < digits.size(); i++) { index.emplace_back(i); }
        backtrack(0, digits);
        if (combinations.empty()) { return ""; }
        // I could remove sort; but to lazy to do it
        stable_sort(combinations.begin(), combinations.end(), greater());
        for (auto &s: combinations) {
            if (valid(s)) {
                stringstream ss;
                ss << s[0] << s[1] << ':' << s[2] << s[3];
                return ss.str();
            }
        }
        return "";
    }

    void backtrack(int first, const vector<int> &digits)
    {
        if (first == digits.size()) {
            vector<int> result;
            result.reserve(digits.size());
            for (int i : index) { result.emplace_back(digits[i]); }
            combinations.emplace_back(result);
        } else {
            for (int i = first; i < index.size(); i++) {
                iter_swap(index.begin() + first, index.begin() + i);
                backtrack(first + 1, digits);
                iter_swap(index.begin() + first, index.begin() + i);
            }
        }
    }

    static bool valid(const vector<int> &s)
    {
        if (s[0] > 2) { return false; }
        if (s[0] == 2 && s[1] > 3) { return false; }
        if (s[2] > 5) { return false; }
        return true;
    }
};


int main()
{
    Solution solution;
    cout << solution.largestTimeFromDigits({0, 0, 0, 2}) << " expected: 20:00" << endl;
    vector<int> vec0{2, 0, 6, 6};
    cout << solution.largestTimeFromDigits(vec0) << " expected: 06:26" << endl;
    vector<int> vec1{1, 2, 3, 4};
    cout << solution.largestTimeFromDigits(vec1) << " expected: 23:41" << endl;
    vector<int> vec2{5, 5, 5, 5};
    cout << solution.largestTimeFromDigits(vec2) << " expected: " << endl;
    vector<int> vec3{0, 0, 1, 0};
    cout << solution.largestTimeFromDigits(vec3) << " expected: 10:00" << endl;
    return 0;
}