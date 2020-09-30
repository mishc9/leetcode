//
// Created by Михаил Степанов on 12.09.2020.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    static int maxSubArraySum(const vector<int> &numbers)
    {
        if (numbers.empty()) { throw invalid_argument("empty vector has no sub-arrays"); }
        int maxSum = numbers[0];
        int currSum = numbers[0];

        for (int i = 1; i < numbers.size(); i++) {
            currSum = max(numbers[i], currSum + numbers[i]);
            maxSum = max(currSum, maxSum);
        }
        return maxSum;
    }

    static int kadane_s_max_sub_array(vector<int> &numbers)
    {
        if (numbers.empty()) { throw invalid_argument("empty vector has no sub-arrays"); }
        int maxSum = numbers[0];
        for (int i = 1; i < numbers.size(); i++) {
            if (numbers[i - 1] > 0) { numbers[i] += numbers[i - 1]; }
            maxSum = max(maxSum, numbers[i]);
        }
        return maxSum;
    }

    static int maxSubArrayProduct(const vector<int> &numbers)
    {
        if (numbers.empty()) { throw invalid_argument("empty vector has no sub-arrays"); }
        int maxProduct = numbers[0];
        int minProduct = numbers[0];
        int currMaxProduct = numbers[0];
        int maxBuffer;
        for (int i = 1; i < numbers.size(); i++) {
            maxBuffer = max({numbers[i], currMaxProduct * numbers[i], minProduct * numbers[i]});
            minProduct = min({numbers[i], currMaxProduct * numbers[i], minProduct * numbers[i]});
            currMaxProduct = maxBuffer;
            maxProduct = max(currMaxProduct, maxProduct);
        }
        return maxProduct;
    }
};

int main()
{
    cout << 6 << " " << Solution::maxSubArraySum({-2, 1, -3, 4, -1, 2, 1, -5, 4}) << endl;
    vector<int> numbers{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << 6 << " " << Solution::kadane_s_max_sub_array(numbers) << endl;
}