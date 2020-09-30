//
// Created by Михаил Степанов on 11.09.2020.
//

#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution
{
public:
    static int maxSubArraySum(const vector<int> &numbers)
    {
        int maxSum = numbers[0];
        int currSum = numbers[0];
        for (int i = 1; i < numbers.size(); i++) {
            currSum = max(numbers[i], currSum + numbers[i]);
            maxSum = max(maxSum, currSum);
        }

        return maxSum;
    }

    static int kadane_s_algorithm(vector<int> &numbers)
    {
        int maxSum = numbers[0];
        for (int i = 1; i < numbers.size(); i++) {
            if (numbers[i - 1] > 0) { numbers[i] += numbers[i - 1]; }
            maxSum = max(numbers[i], maxSum);
        }
        return maxSum;
    }

    static int maxProduct(const vector<int> &numbers)
    {
        int maxProd = numbers[0], currentMaxProd = numbers[0], currentMinProd = numbers[0];
        int maxBuff;
        for (int i = 1; i < numbers.size(); i++) {
            maxBuff = max({numbers[i], currentMaxProd * numbers[i], currentMinProd * numbers[i]});
            currentMinProd = min({numbers[i], currentMaxProd * numbers[i], currentMinProd * numbers[i]});
            currentMaxProd = maxBuff;
            maxProd = max(maxProd, currentMaxProd);
        }
        return maxProd;
    }
};

int main()
{
    // cout << (Solution::maxSubArraySum({0, 1, 2, 3, 4}) == 10) << endl;
    // cout << (Solution::maxSubArraySum({1, -2, 3, 4, -8, 7, -9}) == 7) << endl;
    // vector<int> vec{1, -2, 3, 4, -8, 7, -9};
    // cout << (Solution::kadane_s_algorithm(vec) == 7) << endl;
    vector<pair<int, vector<int>>> cases{
            {4,  {3,  -1, 4}},
            {24, {-2, 3,  -4}},
            {3,  {-3, -1, -1}},
            {0,  {-2, 0,  -1}},
            {6,  {2,  3,  -2, 4}},
            {-2, {-2}},
    };
    for (auto[val, vec]: cases) {
        int result = Solution::maxProduct(vec);
        cout << (result == val) << '\t' << val << '\t' << result << endl;
    }
    return 0;
}
