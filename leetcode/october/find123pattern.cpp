//
// Created by Михаил Степанов on 23.10.2020.
//

#include <vector>
#include <stack>

using namespace std;


class SlowSolution
{
public:
    static bool find132pattern(const vector<int> &nums)
    {
        int minVal = INT_MAX;
        for (int j = 0; j < nums.size() - 1; j++) {
            minVal = min(minVal, nums[j]);
            for (int k = j + 1; k < nums.size(); k++) {
                if (nums[k] < nums[j] && minVal < nums[k])
                    return true;
            }
        }
        return false;
    }
};


class Solution
{
public:

    static bool find132pattern(const vector<int> &nums)
    {
        if (nums.size() < 3) { return false; }
        stack<int> stack;
        vector<int> minValues;
        minValues.reserve(nums.size());

        minValues[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) { minValues[i] = min(minValues[i - 1], nums[i]); }
        for (int j = nums.size() - 1; j >= 0; j--) {
            if (nums[j] > minValues[j]) {
                while (!stack.empty() && stack.top() <= minValues[j]) { stack.pop(); }
                if (!stack.empty() && stack.top() < nums[j]) { return true; }
                stack.push(nums[j]);
            }
        }
        return false;
    }
};

#include <iostream>

int main()
{
    Solution solution;

    vector<pair<vector<int>, bool>> cases{
            {{1,  2, 3, 4}, false},
            {{3,  1, 4, 2}, true},
            {{-1, 3, 2, 0}, true}
    };

    for (auto[vec, answer]: cases) {
        cout << (Solution::find132pattern(vec) == answer) << endl;
    }
    return 0;
}

