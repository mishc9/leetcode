//
// Created by Михаил Степанов on 06.11.2020.
//

#include <vector>
#include <cmath>

using namespace std;

class Solution
{
public:
    static int computeSum(const vector<int> &nums, int divisor)
    {
        int sum = 0;
        for (int num : nums) {
            sum += ceil(num * 1.0 / divisor);
        }
        return sum;
    }

    static int smallestDivisor(vector<int> &nums, int threshold)
    {
        int left = 1, right = nums[nums.size() - 1];

        while (left <= right) {
            int mid = (left + right) / 2;
            int curr = computeSum(nums, mid);

            if (curr > threshold) { left = mid + 1; }
            else { right = mid - 1; }
        }

        return left;
    }
};
