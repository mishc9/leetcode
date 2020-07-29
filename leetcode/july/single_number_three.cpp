//
// Created by Михаил Степанов on 23.07.2020.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {

public:
    vector<int> singleNumber(const vector<int> &vec) {
        int sum = 0;
        for (auto val : vec) { sum ^= val; }
        int low_bit = sum & (-sum);  // find lowest bit in XOR of target numbers
        vector<int> result{0, 0};
        for (auto val : vec) {  // use lowest bit to distinguish between two numbers.
            // It is guaranteed (why?) that the lowest bit is different for target numbers. The rest will nullify.
            if (low_bit & val) { result[0] ^= val; }
            else { result[1] ^= val; }
        }
        return result;
    }
};


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


int main() {
    Solution sol;
    cout << sol.singleNumber({7, 1, 1, 2, 3, 2, 5, 8, 7, 8}) << endl;
    return 0;
}
