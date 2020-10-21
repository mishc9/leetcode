//
// Created by Михаил Степанов on 21.10.2020.
//

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    static int minMeetingRooms(vector<vector<int>> &intervals)
    {
        sort(
                intervals.begin(),
                intervals.end(),
                [](auto &lhs, auto &rhs)
                {
                    if (lhs[0] == rhs[0]) { return lhs[1] < rhs[1]; }
                    else { return lhs[0] < rhs[0]; }
                }
        );
        int maxAllocated = 0;
        vector<vector<int>> allocated;
        for (auto interval: intervals) {
            int front = interval.front();
            while (!allocated.empty() && allocated.front().back() <= front) {
                pop_heap(
                        allocated.begin(),
                        allocated.end(),
                        [](auto &lhs, auto &rhs)
                        { return lhs[1] > rhs[1]; }
                );
                allocated.pop_back();
            }
            allocated.push_back(interval);
            push_heap(
                    allocated.begin(),
                    allocated.end(),
                    [](auto &lhs, auto &rhs)
                    { return lhs[1] > rhs[1]; }
            );
            maxAllocated = max(maxAllocated, int(allocated.size()));
        }
        return maxAllocated;
    }
};

template<typename T>
ostream &operator<<(ostream &os, const vector<T> &vec)
{
    os << "[";
    bool first_step = true;
    for (auto val : vec) {
        if (first_step) {
            first_step = false;
            os << val;
            continue;
        }
        os << ", " << val;
    }
    os << "]";
    return os;
}

int main()
{
    vector<pair<vector<vector<int>>, int>> cases = {
            {{{13, 15}, {1, 13}},           1},
            {{{0,  30}, {5, 10}, {15, 20}}, 2},
            {{{7,  10}, {2, 4}},            1},
    };


    for (auto[input_vectors, correct_answer]: cases) {
        int result = Solution::minMeetingRooms(input_vectors);
        cout << "For input vector " << input_vectors << " output value is " << result
             << ", expected " << correct_answer << ", test " << (correct_answer == result ? "succeed" : "failed")
             << endl;
    }
    return 0;
}
