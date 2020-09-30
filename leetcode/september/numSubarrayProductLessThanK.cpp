//
// Created by Михаил Степанов on 28.09.2020.
//

#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

class Solution
{
public:
    static int numSubarrayProductLessThanK(const vector<int> &nums, int k)
    {
        if (k <= 1) { return 0; }
        int prod = 1, ans = 0, left = 0;

        for (int right = 0; right < nums.size(); right++) {
            prod *= nums[right];
            while (prod >= k) {
                prod /= nums[left++];
            }
            ans += right - left + 1;
        }
        return ans;
    }

    static int _numSubarrayProductLessThanK(const vector<int> &nums, int k)
    {
        if (k == 0) return 0;
        double logK = log(k);
        vector<double> prefix(nums.size() + 1);
        for (int i = 0; i < nums.size(); i++) {
            prefix[i + 1] = prefix[i] + log(nums[i]);
        }

        int ans = 0;
        for (int i = 0; i < prefix.size(); i++) {
            int lo = i + 1, hi = prefix.size();
            while (lo < hi) {
                int mi = lo + (hi - lo) / 2;
                if (prefix[mi] < prefix[i] + logK - 1e-9) lo = mi + 1;
                else hi = mi;
            }
            ans += lo - i - 1;
        }
        return ans;
    }
};


int main()
{
    cout << "Expected 8, got " << Solution::numSubarrayProductLessThanK({10, 5, 2, 6}, 100) << endl;
    cout << "Expected 8, got " << Solution::_numSubarrayProductLessThanK({10, 5, 2, 6}, 100) << endl;
    return 0;
}