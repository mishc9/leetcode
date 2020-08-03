//
// Created by Михаил Степанов on 31.07.2020.
//

#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    // climb a stair doing 1 or 2 steps. How many ways you can climb the stair?
    // It's just a fib number except for the ladder of 0 height where there's zero
    // ways to climb.
    int climbStairs(int n) {
        int n_1 = 1;
        int n_0 = 1;
        if (n == 0) { return 0; }
        if (n == 1) { return n_1; }
        for (int i = 2; i <= n; i++) {
            int buf = n_1;
            n_1 = n_1 + n_0;
            n_0 = buf;
        }
        return n_1;
    }
};

int main() {
    Solution sol;
    cout << sol.climbStairs(1) << endl;
    cout << sol.climbStairs(2) << endl;
    cout << sol.climbStairs(3) << endl;
    cout << sol.climbStairs(4) << endl;
    return 0;
}
