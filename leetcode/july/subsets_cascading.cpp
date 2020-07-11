//
// Created by Михаил Степанов on 11.07.2020.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


template<typename T>
ostream &operator<<(ostream &os, const vector<T> vec) {
    cout << "[";
    for (auto &val :vec) {
        os << val << ", ";
    }
    cout << "]";
    return os;
}


class Solution {
    // looks faster than subsets.cpp; but takes more memory probably.  (May be) easier to understand
public:
    vector<vector<int>> subsets(vector<int> nums) {
        vector<vector<int>> result;
        result.reserve(pow(2, nums.size()));
        vector<int> empty{};
        result.emplace_back(empty);
        for (int &num : nums) {
            int size = result.size();
            for (int j = 0; j < size; j++) { // dangerous: emplace values back while iterate through
                vector<int> new_(result[j]);  // copy of array
                new_.emplace_back(num);
                result.emplace_back(new_);
            }
        }
        return result;
    }
};


int main() {
    Solution sol;
    cout << sol.subsets({1, 2, 3}) << endl;
    return 0;
}
