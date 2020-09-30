//
// Created by Михаил Степанов on 29.09.2020.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    static int numSubarrayProductLessThanK(const vector<int> &nums, int k)
    {
        if (nums.empty() || k <= 1) { return 0; }
        int product = 1;
        int counts = 0;
        int leftPtr = 0;
        for (int rightPtr = 0; rightPtr < nums.size(); rightPtr++) {
            product *= nums[rightPtr];
            while (product >= k) { product /= nums[leftPtr++]; }
            counts += rightPtr - leftPtr + 1;
        }
        return counts;
    }
};

int main()
{
    cout << Solution::numSubarrayProductLessThanK({10, 5, 2, 6}, 100) << endl;
    return 0;
}

