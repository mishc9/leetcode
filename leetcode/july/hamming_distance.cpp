//
// Created by Михаил Степанов on 06.07.2020.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {

        return numberOfSetBits(x ^ y);
    }

    /*
    int _hammingDistance(int x, int y) {
        int diff = x ^y;

        if ((diff == 0) || (diff == 1)) {
            return diff;
        }
        int acc = 0;
        while (diff > 1) {
            acc += diff % 2;
            diff /= 2;
        }
        acc += diff;
        return acc;
    } */

private:
    int numberOfSetBits(int i) {
        // Java: use int, and use >>> instead of >>
        // C or C++: use uint32_t
        i = i - ((i >> 1) & 0x55555555);
        i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
        return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
    }
};


int main() {
    Solution sol;
    cout << sol.hammingDistance(1, 4) << endl;
}
