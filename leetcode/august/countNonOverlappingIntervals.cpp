//
// Created by Михаил Степанов on 17.08.2020.
//

#include <vector>
#include <iostream>

using namespace std;

using Interval = vector<int>;
using IntervalArray = vector<Interval>;

class Solution {

    struct {
        bool operator()(Interval lhs, Interval rhs) { return lhs[1] < rhs[1]; }
    } comp;

public:
    int nonOverlappingCount(IntervalArray &intervals) {
        int count = 0;
        if (intervals.empty()) { return count; }

        sort(intervals.begin(), intervals.end(), comp);
        int previous = 0;
        count++;
        for (int current = 1; current < intervals.size(); current++) {
            if (intervals[previous][1] <= intervals[current][0]) {
                count++;
                previous = current;
            }
        }
        return count;
    }

    int eraseOverlapIntervals(IntervalArray &intervals) {
        return intervals.size() - nonOverlappingCount(intervals);
    }
};

int main() {
    Solution solution;
    IntervalArray intervals{{1, 2},
                            {2, 3},
                            {3, 4},
                            {1, 3}};
    cout << solution.eraseOverlapIntervals(intervals) << endl;
    IntervalArray intervals_small{{1, 2}};
    cout << solution.eraseOverlapIntervals(intervals_small) << endl;
    return 0;
}
