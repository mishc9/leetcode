//
// Created by Михаил Степанов on 14.09.2020.
//

#include <vector>
#include <iostream>

using namespace std;


class Solution
{
public:
    static int rob(const vector<int> &street)
    {
        int current_max = 0;
        int previous_max = 0;
        for (auto house : street) {
            int temp = current_max;
            current_max = max(previous_max + house, current_max);
            previous_max = temp;
        }
        return current_max;
    }
};

int main()
{
    cout << "Expected: 4, got " << Solution::rob({1, 2, 3, 1}) << endl;
    cout << "Expected: 12, got " << Solution::rob({2, 7, 9, 3, 1}) << endl;
    return 0;
}

