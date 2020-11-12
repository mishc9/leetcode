//
// Created by Михаил Степанов on 05.11.2020.
//

#include <vector>

using namespace std;

class Solution
{
public:
    static int minCostToMoveChips(const vector<int> &position)
    {
        int evenCounts = 0, oddCounts = 0;

        for (int pos : position) {
            if (pos % 2 == 0) { evenCounts++; }
            else { oddCounts++; }
        }
        return min(evenCounts, oddCounts);
    }
};

#include <iostream>

int main()
{
    vector<pair<vector<int>, int>> inputs{{{2, 2, 2, 3, 3,},   2},
                                          {{1, 1, 1000000000}, 1}};
    for (auto[inp, value] : inputs) {
        cout << (Solution::minCostToMoveChips(inp) == value) << endl;
    }

    return 0;
}
