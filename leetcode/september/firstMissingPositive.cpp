//
// Created by Михаил Степанов on 30.09.2020.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    static int firstMissingPositive(vector<int> nums)
    {
        int size = nums.size();

        // Base case.
        int contains = 0;
        for (int i = 0; i < size; i++) {
            if (nums[i] == 1) {
                contains++;
                break;
            }
        }

        if (contains == 0) { return 1; }

        // nums = [1]
        if (size == 1) { return 2; }

        // Replace negative numbers, zeros,
        // and numbers larger than size by 1s.
        // After this conversion nums will contain
        // only positive numbers.
        for (int i = 0; i < size; i++) {
            if ((nums[i] <= 0) || (nums[i] > size)) { nums[i] = 1; }
        }

        // Use index as a hash key and number sign as a presence detector.
        // For example, if nums[1] is negative that means that number `1`
        // is present in the array.
        // If nums[2] is positive - number 2 is missing.
        for (int i = 0; i < size; i++) {
            int a = abs(nums[i]);
            // If you meet number a in the array - change the sign of a-th element.
            // Be careful with duplicates : do it only once.
            if (a == size) { nums[0] = -abs(nums[0]); }
            else { nums[a] = -abs(nums[a]); }
        }

        // Now the index of the first positive number
        // is equal to first missing positive.
        for (int i = 1; i < size; i++) { if (nums[i] > 0) { return i; }}

        if (nums[0] > 0) { return size; }

        return size + 1;
    }
};

int main()
{

    vector<int> vec = {3, 4, -1, 1};
    cout << "Expected 2, got " << Solution::firstMissingPositive(vec) << endl;
    vec = {1, 2, 0};
    cout << "Expected 3, got " << Solution::firstMissingPositive(vec) << endl;
    vec = {7, 8, 9, 11, 12};
    cout << "Expected 1, got " << Solution::firstMissingPositive(vec) << endl;

    return 0;
}
