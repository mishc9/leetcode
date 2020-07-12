//
// Created by Михаил Степанов on 12.07.2020.
//

#include <iostream>

using namespace std;

class Solution {
public:
    uint32_t _reverseBits(uint32_t n) {
        if (n == 0) { return n; }
        uint32_t result = 0;
        uint32_t tmp;
        for (int i = 31; i >= 0; i--) {
            if (n % 2 == 1) {
                tmp = 1;
                tmp <<= i;
                result += tmp;
            }
            n /= 2;
        }
        return result;
    }

    uint32_t reverseBits(uint32_t n) {
        // exactly the same efficiency, I guess
        uint32_t result = 0;

        for (int i = 0; i < 31; i++) {
            result = (n % 2) + result << 1;
            n /= 2;
        }
        return result + n % 2;
    }

};

int main() {
    Solution sol;
    cout << sol.reverseBits(0) << endl;
    cout << sol.reverseBits(43261596) << endl;
    cout << sol.reverseBits(4294967293) << endl;
    return 0;
}
