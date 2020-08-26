//
// Created by Михаил Степанов on 15.08.2020.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;


template<typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
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

using Intervals = vector<vector<int>>;
using Interval = vector<int>;

class Solution {

public:
    int _eraseOverlapIntervals(Intervals &intervals) {
        if (intervals.empty()) { return 0; }
        struct {
            bool operator()(Interval &lhs, Interval &rhs) {
                return lhs[0] < rhs[0];
            }
        } f;
        sort(intervals.begin(), intervals.end(), f);
        int prev = 0, count = 0;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[prev][1] > intervals[i][0]) {
                if (intervals[prev][1] > intervals[i][1]) { prev = i; }
                count++;
            } else { prev = i; }
        }
        return count;
    }

    int eraseOverlapIntervals(Intervals &intervals) {
        int removeCount = 0;
        if (intervals.empty()) { return removeCount; }
        struct {
            bool operator()(Interval l, Interval r) { return l[1] < r[1]; }
        } comp;
        sort(intervals.begin(), intervals.end(), comp);
        int previous = 0;
        for (int current = 1; current < intervals.size(); current++) {
            if (intervals[current][0] >= intervals[previous][1]) {
                previous = current;
            } else {
                removeCount++;
            }
        }
        return removeCount;
    }
};


int main() {
    Solution solution;
    Intervals intervals{{1, 2},
                        {2, 3},
                        {3, 4},
                        {1, 3}};
    cout << solution.eraseOverlapIntervals(intervals) << endl;
    return 0;
}