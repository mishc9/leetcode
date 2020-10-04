//
// Created by Михаил Степанов on 03.10.2020.
//

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

using namespace std;

using Numbers = const vector<int> &;

int subArraySum(const vector<int> &nums, int k)
{
    int currentSum = 0;
    int result = 0;
    unordered_map<int, int> memory;
    memory[0]++;
    if (nums.empty()) { return result; }
    for (auto num: nums) {
        currentSum += num;
        result += memory[currentSum - k];
        memory[currentSum]++;
    }
    return result;
}

struct pairHash
{
    inline size_t operator()(const pair<int, int> &p) const
    {
        return p.first * 31 + p.second;
    }
};

class Solution
{
public:
    int findPairs(Numbers numbers, int k)
    {
        int result = 0;
        unordered_map<int, int> hash;
        if (k < 0 || numbers.size() < 2) { return result; }
        for (auto num: numbers) {
            hash[num]++;
        }
        for (auto[x, val]: hash) {
            if (k > 0 && hash.count(x + k) != 0) { result++; }
            else if (k == 0 && val > 1) { result++; }
        }
        return result;
    }
};

int main()
{
    cout << subArraySum({1, -1, 1, -1}, 0) << endl;
    cout << subArraySum({0, 0, 0, 0}, 0) << endl;
    cout << subArraySum({10, 2, -2, -20, 10}, -10) << endl;

    cout << "-----" << endl;

    Solution solution;
    cout << "Expected 2, got " << solution.findPairs({3, 1, 4, 1, 5}, 2) << endl;
    cout << "Expected 4, got " << solution.findPairs({1, 2, 3, 4, 5}, 1) << endl;
    cout << "Expected 1, got " << solution.findPairs({1, 3, 1, 5, 4}, 0) << endl;
    cout << "Expected 2, got " << solution.findPairs({1, 2, 4, 4, 3, 3, 0, 9, 2, 3}, 3) << endl;
    cout << "Expected 2, got " << solution.findPairs({-1, -2, -3}, 1) << endl;
    return 0;
}

