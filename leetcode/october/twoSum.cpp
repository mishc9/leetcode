//
// Created by Михаил Степанов on 14.10.2020.
//

#include <vector>

using namespace std;


class TwoSum
{
    vector<int> nums;
    bool is_sorted;

public:
    TwoSum() : is_sorted(false) {}

    void add(int number)
    {
        nums.emplace_back(number);
        is_sorted = false;
    }

    bool find(int value)
    {
        if (!is_sorted) {
            sort(nums.begin(), nums.end());
            is_sorted = true;
        }
        int low = 0, high = nums.size() - 1;

        while (low < high) {
            int twoSum = nums[low] + nums[high];
            if (twoSum < value) { low += 1; }
            else if (twoSum > value) { high -= 1; }
            else { return true; }
        }
        return false;
    }
};
