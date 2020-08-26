//
// Created by Михаил Степанов on 17.08.2020.
//

#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

template<typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
    os << "[";
    bool first_step = true;
    for (auto val : vec) {
        if (first_step) {
            first_step = false;
            os << val;
            continue;
        }
        os << ", " << val;
    }
    os << "]";
    return os;
}

class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        int n = num_people;
        int p = (int) (sqrt(2 * candies + 0.25) - 0.5);
        int remaining = (int) (candies - (p + 1) * p * 0.5);
        int rows = p / n, cols = p % n;

        vector<int> distribution(n, 0);
        for (int i = 0; i < n; ++i) {
            distribution[i] = (i + 1) * rows + (int) (rows * (rows - 1) * 0.5) * n;
            if (i < cols) {
                distribution[i] += i + 1 + rows * n;
            }
        }
        distribution[cols] += remaining;
        return distribution;
    }
};

int main() {
    Solution solution;
    return 0;
}