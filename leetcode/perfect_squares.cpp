//
// Created by Михаил Степанов on 28.06.2020.
//
#include <iostream>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
    /*
     * Using Lagrange 4 squares theorem & explanation from here
     * https://leetcode.com/problems/perfect-squares/discuss/707526/Python-Fastest-O(sqrt(n))-solution-with-math-explanied.
     */
public:
    int numSquares(int n) {
        if ((n == 1) || (n == 0)) {
            return n;
        }
        if (fullSquare(n)) {
            return 1;
        }
        for (int i = 1; (float) i < sqrt(n); i++) {
            if (fullSquare(n - i * i)) {
                return 2;
            }
        }
        while (n % 4 == 0) {
            n >>= 2;
        }
        if (n % 8 == 7) {
            return 4;
        }
        return 3;
    }

    bool fullSquare(int n) {
        return pow((int) sqrt(n), 2) == n;
    }

    int numSquaresDP(int n) {
        if ((n == 0) || (n == 1)) {
            return n;
        }
        vector<int> squares = findSquares(n);
        int cols = n + 1;
        vector<int> mat;
        mat.reserve(cols);
        for (int i = 0; i < cols; i++) {
            mat.emplace_back(i);
        }
        // mat[0] = 0;

        for (auto s : squares) {
            for (int j = s; j < cols; j++) {
                mat[j] = min(mat[j], 1 + mat[j - s]);
            }
        }
        return mat[n];
    }

    vector<int> findSquares(int n) {
        vector<int> squares;
        for (int i = 2; i * i <= n; i++) {
            squares.emplace_back(i * i);
        }
        return squares;
    }
};

int main() {
    Solution sol = Solution();
    cout << sol.numSquares(8) << endl;
    cout << sol.numSquares(12) << endl;
    cout << sol.numSquares(13) << endl;
    cout << sol.numSquares(16) << endl;
    cout << sol.numSquares(62) << endl;
    cout << sol.numSquares(7212) << endl;
    return 0;
}