//
// Created by Михаил Степанов on 14.10.2020.
//

#include <vector>

using namespace std;

class Solution
{
public:
    static int rob(const vector<int> &nums)
    {

        if (nums.empty()) { return 0; }

        if (nums.size() == 1) { return nums[0]; }

        int max1 = robHelper(nums, 0, nums.size() - 2);
        int max2 = robHelper(nums, 1, nums.size() - 1);

        return max(max1, max2);
    }

    static int robHelper(const vector<int> &nums, int start, int end)
    {
        int robbed = 0;
        int robbedPrevStep = 0;

        for (int i = start; i <= end; i++) {
            int temp = robbed;
            int current = nums[i];
            robbed = max(current + robbedPrevStep, robbed);
            robbedPrevStep = temp;
        }

        return robbed;
    }
};

#include <iostream>

int main()
{
    cout << Solution::rob({2, 3, 2}) << " 3" << endl;
    cout << Solution::rob({1, 2, 3, 1}) << " 4" << endl;

    return 0;
}