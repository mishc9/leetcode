//
// Created by Михаил Степанов on 12.07.2020.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool canWinNim(int n) {
        if (n == 0) { return false; }
        return n % 4 != 0;
    }

    int hammingDistance(int x, int y) {
        int result = 0;
        for (int i = 0; i < 32; i++) {
            result += (x % 2 != y % 2);
            x /= 2;
            y /= 2;
        }
        return result;
    }
};


int main() {
    Solution sol;
    cout << sol.hammingDistance(0, 0) << endl;
    cout << sol.hammingDistance(0, 8) << endl;
    cout << sol.hammingDistance(1, 4) << endl;
    cout << sol.hammingDistance(0, 7) << endl;
    cout << sol.hammingDistance(8, 7) << endl;
    return 0;
}

