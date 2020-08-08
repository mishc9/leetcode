//
// Created by Михаил Степанов on 06.08.2020.
//

#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    vector<int> findDuplicates(vector<int> &nums) {
        vector<int> result;
        for (auto num: nums) {
            if (nums[abs(num) - 1] < 0) {
                result.emplace_back(abs(num));
                // nums[abs(num) - 1] *= -1;
            }
            nums[abs(num) - 1] *= -1;
        }
        for (int &num : nums) {
            if (num < 0) { num *= -1; }
        }
        return result;
    }
};


class Duplicates {
    vector<int> findDuplicates(vector<int> &nums) {
        vector<int> result;
        for (auto num: nums) {
            if (nums[abs(num) - 1] < 0) {
                result.emplace_back(num);
            }
            nums[abs(num) - 1] *= -1;
        }
        return result;

    }

};

template<typename T>
ostream &operator<<(ostream &os, const vector<T> vec) {
    cout << "[";
    for (auto &val :vec) {
        os << val << ", ";
    }
    cout << "]";
    return os;
}

int main() {
    Solution solution;
    vector<int> vec{1, 2, 2, 4, 3};
    cout << solution.findDuplicates(vec) << endl;
    cout << vec;
    return 0;
}