//
// Created by Михаил Степанов on 29.10.2020.
//

#include <vector>

using namespace std;

class Solution
{
public:
    static int maxDistToClosest(const vector<int> &seats)
    {
        bool firstStep = true;
        int maxDistInBetween = 0;
        int currDistInBetween = 0;
        for (int i = 0; i < seats.size();) {
            while (i < seats.size() && seats[i] == 0) {
                i++;
                currDistInBetween++;
            }
            currDistInBetween = (firstStep || i == seats.size()) ? currDistInBetween : (currDistInBetween - 1) / 2 + 1;
            if (firstStep) { firstStep = false; }
            maxDistInBetween = max(maxDistInBetween, currDistInBetween);
            currDistInBetween = 0;
            while (i < seats.size() && seats[i] == 1) { i++; }
        }
        return maxDistInBetween;
    }
};

#include <iostream>

int main()
{
    cout << (Solution::maxDistToClosest({1, 0, 0, 0}) == 3) << endl;
    cout << (Solution::maxDistToClosest({1, 0, 0, 0, 1, 0, 1}) == 2) << endl;
    cout << (Solution::maxDistToClosest({0, 1}) == 1) << endl;

    return 0;
}
