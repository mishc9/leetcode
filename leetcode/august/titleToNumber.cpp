//
// Created by Михаил Степанов on 10.08.2020.
//


#include <string>
#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int titleToNumberLeftToRight(const string &s) {
        // Left to right
        int number = 0;
        int base = 26;
        int size = s.size();
        for (int i = 0; i < size; i++) {
            int c = s[i] - 64;
            number += c * pow(base, size - i - 1);
        }
        return number;
    }

    int titleToNumber(const string &s) {
        // Even more left to right
        int number = 0;

        for (char i : s) {
            number *= 26;
            number += (i - int('A') + 1);
        }
        return number;
    }
};


int main() {
    Solution solution;
    cout << (solution.titleToNumber("A") == 1) << endl;
    cout << (solution.titleToNumber("AB") == 28) << endl;
    cout << (solution.titleToNumber("ZY") == 701) << endl;
    return 0;
}
