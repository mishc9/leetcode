//
// Created by Михаил Степанов on 12.09.2020.
//

#include <vector>
#include <iostream>

using namespace std;

using table = vector<vector<int>>;

class Solution
{
    table combinationsTable;
    vector<int> workingCombination;
    int k_target;

public:
    table combinationSum3(int k, int n)
    {
        if (k == 0 || n == 0) { throw invalid_argument("k or n couldn't be zero"); }
        combinationsTable = {};
        workingCombination = {};
        k_target = k;
        backTrack(n, 0);
        return combinationsTable;
    }

private:
    void backTrack(int remain, int next_position)
    {
        if (remain == 0 && workingCombination.size() == k_target) {
            combinationsTable.emplace_back(workingCombination);
            return;
        }
        if (remain < 0 || workingCombination.size() == k_target) {
            return;
        }
        for (int i = next_position; i < 9; i++) {
            workingCombination.emplace_back(i + 1);
            backTrack(remain - i - 1, i + 1);
            workingCombination.pop_back();
        }
    }
};
