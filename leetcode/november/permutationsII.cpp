//
// Created by Михаил Степанов on 12.11.2020.
//

#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<vector<int>> results;

        unordered_map<int, int> counter;
        for (int &num : nums) { counter[num]++; }

        vector<int> permutation;
        backtrack(permutation, nums.size(), counter, results);
        return results;
    }

    void backtrack(
            vector<int> &permutation,
            int size,
            unordered_map<int, int> &counter,
            vector<vector<int>> &results)
    {

        if (permutation.size() == size) {
            results.emplace_back(permutation);
            return;
        }

        for (auto[num, count] : counter) {
            if (count == 0) { continue; }
            permutation.emplace_back(num);
            counter[num] = count - 1;

            backtrack(permutation, size, counter, results);

            permutation.pop_back();
            counter[num] = count;
        }
    }
};

class _Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        unordered_map<int, int> counter;
        for (auto &num: nums) { counter[num]++; }
        vector<vector<int>> combinations;


    }

    int backtrack()
    {

    }
};
