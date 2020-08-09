//
// Created by Михаил Степанов on 09.08.2020.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    int subarraySum(const vector<int> &array, int targetSum) {
        int result = 0;
        int32_t currentSum = 0, diff;
        unordered_map<int32_t, int16_t> hash;

        hash[0]++;
        for (auto val : array) {
            currentSum += val;
            diff = currentSum - targetSum;
            if (hash.count(diff) != 0) { result += hash.at(diff); }
            hash[currentSum]++;
        }
        return result;
    }

    int subarraySumFast(const vector<int> &nums, int k) {
        unordered_map<int32_t, int16_t> sumsUpTo;
        int numberOfSubArrays = 0;
        int32_t sum = 0;
        int32_t diff;
        ++sumsUpTo[0];
        for (int num : nums) {
            sum += num;
            if (k == 0) {
                numberOfSubArrays += sumsUpTo[sum];
                ++sumsUpTo[sum];
            } else {
                ++sumsUpTo[sum];
                diff = sum - k;
                if (sumsUpTo.count(diff) != 0) {
                    numberOfSubArrays += sumsUpTo[diff];
                }
            }
        }
        return numberOfSubArrays;
    }
};


int main() {
    Solution solution;
    cout << solution.subarraySum({1, -1, 1, -1}, 0) << endl;
    cout << solution.subarraySum({0, 0, 0, 0}, 0) << endl;
    cout << solution.subarraySum({10, 2, -2, -20, 10}, -10) << endl;
    return 0;
}
