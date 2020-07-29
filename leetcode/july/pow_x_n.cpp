//
// Created by Михаил Степанов on 16.07.2020.
//


class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0 || n == 1) { return n == 0 ? 1 : x; }
        if (n == -1) { return 1 / x; }
        double pow = myPow(x, n / 2);
        if (n % 2 == 0) { return pow * pow; }
        else { return pow * pow * (n < 0 ? (1 / x) : x); }
    }
};