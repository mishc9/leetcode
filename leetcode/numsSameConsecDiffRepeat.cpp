//
// Created by Михаил Степанов on 19.08.2020.
//

#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        if (n == 0) { return {}; }
        if (n == 1) { return {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; }
        vector<int> result;
        for (int num = 1; num < 10; num++) { dfs(result, num, n - 1, k); }
        return result;
    }

    void dfs(vector<int> &result, int num, int n, int k) {
        if (n == 0) {
            result.emplace_back(num);
            return;
        }
        int tailDigit = num % 10;

        if (k == 0) {
            dfs(result, num * 10 + tailDigit, n - 1, k);
            return;
        }
        if (tailDigit + k < 10) { dfs(result, num * 10 + (tailDigit + k), n - 1, k); }
        if (tailDigit - k >= 0) { dfs(result, num * 10 + (tailDigit - k), n - 1, k); }

        // nextDigit.emplace_back(tailDigit + k);
        // if (k != 0) { nextDigit.emplace_back(tailDigit - k); }
        // for (auto digit: nextDigit) {
        //     if (0 <= digit && digit < 10) {
        //         int nextNum = num * 10 + digit;
        //         dfs(result, nextNum, n - 1, k);
        //     }
        // }
    }
};