//
// Created by Михаил Степанов on 28.06.2020.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        {
            // Initialize result
            int result = 0;
            short sum;

            // Iterate through every bit
            for (int i = 0; i < sizeof(int) * 8; i++) {

                // Find sum of set bits at ith position in all
                // array elements
                sum = 0;
                for (int j = 0; j < nums.size(); j++) {
                    if (nums[j] & (1 << i)) {
                        sum++;
                    }
                }

                // The bits with sum not multiple of 3, are the
                // bits of element with single occurrence.
                if (sum % 3) {
                    result |= (1 << i);
                }
            }

            return result;
        }
    }
};

int main() {
    Solution sol = Solution();
    vector<int> vec = {0, 1, 0, 1, 0, 1, 99};
    cout << sol.singleNumber(vec) << endl;

    return 0;
}