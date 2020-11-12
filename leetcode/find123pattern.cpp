//
// Created by Михаил Степанов on 24.10.2020.
//

#include <vector>
#include <stack>

using namespace std;

class Solution
{
    bool find123pattern(const vector<int> &nums)
    {
        if (nums.size() < 3) { return false; }

        vector<int> minValues(nums.size());
        minValues[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            minValues[i] = min(minValues[i - 1], nums[i]);
        }
        stack<int> stack;

        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] > minValues[i]) {
                while (!stack.empty() && stack.top() <= minValues[i]) { stack.pop(); }
                if (!stack.empty() && stack.top() < nums[i]) { return true; }
                stack.push(nums[i]);
            }
        }
        return false;
    }
};
