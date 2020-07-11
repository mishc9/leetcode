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
    // wew. Passed on the first try!
public:
    vector<vector<int>> subsets(vector<int> nums) {
        vector<vector<int>> result;
        vector<bool> support(nums.size(), 0);
        for (int i = 0; i < pow(2, nums.size()); i++) {
            vector<int> subset{};
            for (int j = 0; j < nums.size(); j++) {
                if (support[j]) {
                    subset.emplace_back(nums[j]);
                }
            }
            result.emplace_back(subset);
            incrementSupport(support);
        }
        return result;
    }

private:
    void incrementSupport(vector<bool> &support) {
        for (int i = support.size() - 1; i >= 0; --i) {
            if (!support[i]) {
                support[i] = true;
                return;
            }
            support[i] = false;
        }
    }
};


int main() {
    Solution sol;
    cout << sol.subsets({1, 2, 3}) << endl;
    return 0;
}