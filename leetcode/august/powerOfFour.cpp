//
// Created by Михаил Степанов on 04.08.2020.
//


#include <iostream>

class Solution {

public:
    bool isPowerOfFour(int num) {
        // Seems to be a most efficient solution
        if ((num <= 0) || ((num - 1) & num) != 0) { return false; }
        // return (((num & 0x55555555) & ((num & 0x55555555) - 1)) == 0);  // BROKEN (why?)
        // return (numberOfSetBits(num & 0x55555555)) == 1; // OK, but slower
        return (num & 0x55555555) != 0; // OK, but slower
    }

    bool isPowerOfFourEff(int num) {
        // Seems to be a most efficient solution
        int val = num & 0x55555555;
        if (!val) { return false; }
        return ((num & (num - 1)) == 0) && ((val & (val - 1)) == 0);
    }

    bool _isPowerOfFour(int num) {
        int mask = 0x55555555;
        return (numberOfSetBits(num) == 1) && numberOfSetBits(num & mask) == 1;
    }

    bool __isPowerOfFour(int num) {
        /* Based on the following arithmetic:
         * x = 2^(2k) mod 3
         * x = 2^(2k) = 2^(2^k) = 4^k = (3 + 1)^k mod 3
         * decompose (3 + 1)^k = (3 + 1) (3 + 1)^(k-1) = 3(3 + 1)^(k-1) + (3 + 1)^(k-1)
         * remove 0 first term, (3 + 1)^k = (3 + 1)^(k - 1) mod 3
         * hence, (3 + 1)^k = (3 + 1) mod 3 = 1
         *
         * So, the first term neglects zero; second term checks if num is the power of two (?);
         * third term checks if this is actually a power of four (it should be equals 1 as we've seen before)
         *
         * Takeouts:
         *  - power of four mod 3 is always equals 1
         *  - x & (x - 1) == 0 iff x is a power of two
         */
        return (num > 0) && ((num & (num - 1)) == 0) && (num % 3 == 1);
    }

private:
    int numberOfSetBits(uint32_t i) {
        // Java: use int, and use >>> instead of >>
        // C or C++: use uint32_t
        i = i - ((i >> 1) & 0x55555555);
        i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
        return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
    }
};


int main() {
    Solution solution;
    std::cout << "0 " << (solution.isPowerOfFour(0) == 0) << std::endl;
    std::cout << "1 " << (solution.isPowerOfFour(1) == 1) << std::endl;
    std::cout << "2 " << (solution.isPowerOfFour(2) == 0) << std::endl;
    std::cout << "3 " << (solution.isPowerOfFour(3) == 0) << std::endl;
    std::cout << "4 " << (solution.isPowerOfFour(4) == 1) << std::endl;
    std::cout << "5 " << (solution.isPowerOfFour(5) == 0) << std::endl;
    std::cout << "6 " << (solution.isPowerOfFour(6) == 0) << std::endl;
    std::cout << "7 " << (solution.isPowerOfFour(7) == 0) << std::endl;
    std::cout << "8 " << (solution.isPowerOfFour(8) == 0) << std::endl;
    std::cout << "16 " << (solution.isPowerOfFour(16) == 1) << std::endl;

    return 0;
}

