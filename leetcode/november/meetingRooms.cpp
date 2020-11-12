//
// Created by Михаил Степанов on 01.11.2020.
//

#include <vector>

using namespace std;

class Solution
{
public:
    static bool canAttendMeetings(vector<vector<int>> &intervals)
    {
        if (intervals.size() < 1) { return true; }
        sort(intervals.begin(),
             intervals.end(),
             [](auto &lhs, auto &rhs)
             {
                 if (lhs[0] == rhs[0]) { return lhs[1] < rhs[1]; }
                 else { return lhs[0] < rhs[0]; }
             }
        );
        for (int i = 0; i < intervals.size() - 1; i++) {
            if (intervals[i][1] > intervals[i + 1][0]) {
                return false;
            }
        }
        return true;
    }
};

#include <iostream>

using namespace std;

int main()
{
    vector<vector<int>> vec = {{7, 10},
                               {2, 4}};
    cout << Solution::canAttendMeetings(vec) << endl;
    vec = {{0,  30},
           {5,  10},
           {15, 20}};
    cout << !Solution::canAttendMeetings(vec) << endl;
    return 0;
}