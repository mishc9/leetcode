//
// Created by Михаил Степанов on 02.07.2020.
//
#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        auto n_f = (double)n;
        double val = (-1 + sqrt(1 + 8 * n_f)) / 2;
        return (int)floor(val);
    }
};

int main() {
    Solution sol = Solution();
    cout << sol.arrangeCoins(5) << endl;
    cout << sol.arrangeCoins(8) << endl;
    cout << sol.arrangeCoins(10) << endl;
    return 0;
}
