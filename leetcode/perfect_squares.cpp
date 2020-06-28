//
// Created by Михаил Степанов on 28.06.2020.
//
#include <cmath>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        if ((n == 0) || (n == 1)) {
            return n;
        }
        vector<int> squares = findSquares(n);
        int cols = n + 1;
        vector<int> mat;
        mat.reserve(cols);
        for (int i = 0; i < cols; i++) {
            mat.emplace_back(n);
        }
        mat[0] = 0;

        for (auto s : squares) {
            for (int j = s; j < cols; j++) {
                mat[j] = min(mat[j], 1 + mat[j - s]);
            }
        }
        return mat[n];

/*
        int root = floor(sqrt(n));
        if (n == root * root) {
            return 1;
        }
        int best = n;
        int ns, result;
        for (int i = root; i > 0; i--) {
            int k = n - i * i;
            if (cache.count(k)) {
                result = cache.at(k);
            } else {
                result = numSquaresOld(k);
                cache[k] = result;
            }

            ns = 1 + result;
            if (ns < best) {
                best = ns;
            }
        }
        return best;*/
    }

    vector<int> findSquares(int n) {
        vector<int> squares;
        for (int i = 1; i * i <= n; i++) {
            squares.emplace_back(i * i);
        }
        return squares;
    }

    /*
private:
    map<int, int> cache;
     */
};

int main() {
    Solution sol = Solution();
    cout << sol.numSquares(12) << endl;
    cout << sol.numSquares(13) << endl;
    cout << sol.numSquares(16) << endl;
    cout << sol.numSquares(62) << endl;
    cout << sol.numSquares(7212) << endl;
    return 0;
}