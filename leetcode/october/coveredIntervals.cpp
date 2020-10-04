//
// Created by Михаил Степанов on 04.10.2020.
//

#include <vector>
#include <iostream>

using namespace std;

using Interval = vector<int>;
using Intervals = vector<Interval> &;


class _Solution
{
    struct
    {
        bool operator()(const Interval &lv, const Interval &rv)
        {
            if (lv[0] == rv[0]) {
                return lv[1] > rv[1];
            } else {
                return lv[0] < rv[0];
            }
        }
    } comp;

    struct
    {
        bool operator()(const vector<int> &lv, const vector<int> &rv)
        {
            return lv[0] < rv[0];
        }
    } sortLeftAscending;

    struct
    {
        bool operator()(const vector<int> &lv, const vector<int> &rv)
        {
            return lv[1] > rv[1];
        }
    } sortRightDescending;

public:
    int removeCoveredIntervals(Intervals intervals)
    {
        if (intervals.size() < 2) { return intervals.size(); }

        // stable_sort(intervals.begin(), intervals.end(), sortRightDescending);
        stable_sort(intervals.begin(), intervals.end(), comp);
        int counts = intervals.size();
        for (
                auto thisInterval = intervals.begin(), otherInterval = intervals.begin();
                otherInterval != intervals.end();) {
            if ((*otherInterval)[1] > (*thisInterval)[1]) {
                thisInterval++;
            } else if (thisInterval != otherInterval) {
                counts--;
                otherInterval++;
            } else {
                otherInterval++;
            }
        }
        return counts;
    }
};


class Solution
{
    struct
    {
        bool operator()(const Interval &lv, const Interval &rv)
        {
            if (lv[0] == rv[0]) {
                return lv[1] > rv[1];
            } else {
                return lv[0] < rv[0];
            }
        }
    } comp;

    int removeCoveredIntervals(Intervals intervals)
    {
        if (intervals.size() <= 1) { return intervals.size(); }
        sort(intervals.begin(), intervals.end(), comp);
        int count = 0;
        int end, prevEnd = 0;
        for (auto interval: intervals) {
            end = interval[1];
            if (prevEnd < end) {
                count++;
                prevEnd = end;
            }
        }
        return count;
    }
};

// Fixme: non-constant input
//int main()
//{
//    Solution solution;
//    cout << "Expected 2, got " << solution.removeCoveredIntervals(
//            {{1, 4},
//             {3, 6},
//             {2, 8}}) << endl;
//    cout << "Expected 1, got " << solution.removeCoveredIntervals(
//            {{1, 4},
//             {2, 3}}) << endl;
//    cout << "Expected 2, got " << solution.removeCoveredIntervals(
//            {{0, 10},
//             {5, 12}}) << endl;
//    cout << "Expected 2, got " << solution.removeCoveredIntervals(
//            {{3, 10},
//             {4, 10},
//             {5, 11}}) << endl;
//    cout << "Expected 1, got " << solution.removeCoveredIntervals(
//            {{1, 2},
//             {1, 4},
//             {3, 4}}) << endl;
//    return 0;
//}
