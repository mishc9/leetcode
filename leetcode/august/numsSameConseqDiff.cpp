//
// Created by Михаил Степанов on 18.08.2020.
//

#include <vector>
#include <unordered_map>

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
    }
};

class _SolutionOld {
public:
    vector<int> _numsSameConsecDiff(int N, int K) {
        vector<int> result;


    }


    vector<int> numsSameConsecDiff(int N, int K) {
        if (N == 1) { return {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; }

        vector<int> results;
        for (int num = 1; num < 10; ++num) { DFS(N - 1, num, K, results); }

        return results;
    }

    void DFS(int N, int num, int K, vector<int> &results) {
        if (N == 0) {
            results.emplace_back(num);
            return;
        }
        vector<int> nextDigits;

        int tailDigit = num % 10;
        nextDigits.emplace_back(tailDigit + K);
        if (K != 0) {
            nextDigits.emplace_back(tailDigit - K);
        }
        for (auto nextDigit : nextDigits) {
            if (0 <= nextDigit && nextDigit < 10) {
                int newNum = num * 10 + nextDigit;
                DFS(N - 1, newNum, K, results);
            }
        }
    }

private:
    vector<int> arange{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> six{0, 1, 2, 3, 6, 7, 8, 9};
    vector<int> seven{0, 1, 2, 7, 8, 9};
    vector<int> eight{0, 1, 8, 9};
    vector<int> nine{0, 9};
    unordered_map<int, vector<int> &> allowedValues{
            {0, arange},
            {1, arange},
            {2, arange},
            {3, arange},
            {4, arange},
            {5, arange},
            {6, six},
            {7, seven},
            {8, eight},
            {9, nine}
    };
};
