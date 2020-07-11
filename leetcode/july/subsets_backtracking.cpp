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
    // backtracking is the fastest and most memory-efficient solution (at least for leetcode test cases)
    // For me this one was hardest to understand but it's the best out of two other (binary sorted & cascade)
public:
    vector<vector<int>> subsets(vector<int> nums) {
        // the main idea is to generate all possible subsets of size k. I.e of size 0, 1, 2, ..., nums.size().
        vector<vector<int>> result;
        for (int k = 0; k < nums.size() + 1; k++) {
            vector<int> new_{};
            backtrack(0, result, new_, nums, k);
        }
        return result;
    }

private:
    void backtrack(int start, vector<vector<int>> &result, vector<int> &curr, const vector<int> &nums, int k) {
        if (curr.size() == k) { result.emplace_back(curr); }

        for (int i = start; i < nums.size(); i++) {
            curr.emplace_back(nums[i]);
            backtrack(i + 1, result, curr, nums, k);
            curr.pop_back();
        }
    }
};


int main() {
    Solution sol;
    cout << sol.subsets({1, 2, 3}) << endl;
    return 0;
}

