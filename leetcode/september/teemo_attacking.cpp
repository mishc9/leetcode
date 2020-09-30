//
// Created by Михаил Степанов on 27.09.2020.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    static int findPublicDuration(const vector<int> &timeSeries, int duration)
    {
        if (timeSeries.empty()) { return 0; }
        int totalPoisoned = 0;
        for (int i = 0; i < timeSeries.size() - 1; i++) {
            totalPoisoned += min(timeSeries[i + 1] - timeSeries[i], duration);
        }
        return totalPoisoned + duration;
    }
};

int main()
{
    cout << "Expected 4 " << Solution::findPublicDuration({1, 4}, 2) << endl;
    cout << "Expected 3 " << Solution::findPublicDuration({1, 2}, 2) << endl;
    return 0;
}