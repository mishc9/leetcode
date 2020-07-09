//
// Created by Михаил Степанов on 04.07.2020.
//

#include <vector>
#include <iostream>
#include <map>

using namespace std;


template<typename T>
ostream &operator<<(ostream &s, const vector<T> &vec) {
    for (auto a: vec) {
        s << a;
    }
    return s;
}


class Solution {
public:
    static vector<int> prisonAfterNDays(vector<int> &res, int n) {
        vector<int> tmp(8);
        vector<vector<int>> seen;
        while (n--) {
            for (int i = 1; i < 7; i++) {
                tmp[i] = res[i - 1] == res[i + 1];
            }
            if (!seen.empty() && seen.front() == tmp) { return seen[n % seen.size()]; }
            else seen.push_back(tmp);
            res = tmp;
        }
        return res;
    }
};

int main() {
    vector<int> inp{0, 1, 0, 1, 1, 0, 0, 1};
    auto sol = Solution();
    cout << sol.prisonAfterNDays(inp, 7) << endl;
    vector<int> long_vec{1, 0, 0, 1, 0, 0, 1, 0};
    cout << sol.prisonAfterNDays(long_vec, 1000000) << endl;
    vector<int> long_vec_2{1, 0, 0, 1, 0, 0, 1, 0};
    cout << sol.prisonAfterNDays(long_vec_2, 1000000000) << endl;
    return 0;
}