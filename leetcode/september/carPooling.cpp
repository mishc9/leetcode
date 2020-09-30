//
// Created by Михаил Степанов on 21.09.2020.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    static bool carPooling(const vector<vector<int>> &trips, int capacity)
    {
        vector<int> timeStamps(1001, 0);

        for (auto trip : trips) {
            timeStamps[trip[1]] += trip[0];
            timeStamps[trip[2]] -= trip[0];
        }

        int currentOccupation = 0;

        for (auto number : timeStamps) {
            currentOccupation += number;
            if (currentOccupation > capacity) { return false; }
        }
        return true;
    }
};

int main()
{
    cout << "false " << Solution::carPooling({{2, 1, 5},
                                              {3, 3, 7}}, 4) << endl;
    cout << "true " << Solution::carPooling({{2, 1, 5},
                                             {3, 3, 7}}, 5) << endl;
    cout << "true " << Solution::carPooling({{2, 1, 5},
                                             {3, 5, 7}}, 3) << endl;
    cout << "true " << Solution::carPooling({{3, 2, 7},
                                             {3, 7, 9},
                                             {8, 3, 9}}, 11) << endl;
    return 0;
}

