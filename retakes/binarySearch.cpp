//
// Created by Михаил Степанов on 13.10.2020.
//

#include <vector>

using namespace std;

class Solution
{
public:
    static int search(const vector<int> &nums, int target)
    {
        int leftPrt = 0;
        int rightPtr = nums.size() - 1;
        int pivot;

        while (leftPrt <= rightPtr) {
            pivot = leftPrt + (rightPtr - leftPrt) / 2;
            if (nums[pivot] == target) { return pivot; }
            else if (target < nums[pivot]) { rightPtr = pivot - 1; }
            else { leftPrt = pivot + 1; }
        }
        return -1;
    }
};
