//
// Created by Михаил Степанов on 10.10.2020.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution
    // Inefficient version with redundant copy but const input
{
    static struct
    {
        bool operator()(const vector<int> &ls, const vector<int> &rs)
        {
            return ls[1] < rs[1];
        }
    } SegmentComp;

public:
    static int findMinArrowShots(const vector<vector<int>> &points)
    {
        if (points.size() < 1) { return points.size(); }

        vector<vector<int>> pointsCopy(points);
        sort(pointsCopy.begin(), pointsCopy.end(), SegmentComp);
        int nArrows = 1;

        int Start, End, coverEnd = pointsCopy[0][1];
        for (auto point : pointsCopy) {
            Start = point[0];
            End = point[1];
            if (coverEnd < Start) {
                nArrows++;
                coverEnd = End;
            }
        }
        return nArrows;
    }
};

// For site

class _Solution
{
    static struct
    {
        bool operator()(const vector<int> &ls, const vector<int> &rs)
        {
            return ls[1] < rs[1];
        }
    } SegmentComp;

public:
    static int findMinArrowShots(vector<vector<int>> &pointsCopy)
    {
        if (pointsCopy.size() < 1) { return pointsCopy.size(); }

        sort(pointsCopy.begin(), pointsCopy.end(), SegmentComp);
        int nArrows = 1;

        int Start, End, coverEnd = pointsCopy[0][1];
        for (auto point : pointsCopy) {
            Start = point[0];
            End = point[1];
            if (coverEnd < Start) {
                nArrows++;
                coverEnd = End;
            }
        }
        return nArrows;
    }
};

int main()
{
    Solution solution;
    cout << "Expected 2, git " << Solution::findMinArrowShots({{9, 12},
                                                               {1, 10},
                                                               {4, 11},
                                                               {8, 12},
                                                               {3, 9},
                                                               {6, 9},
                                                               {6, 7}}) << endl;
    cout << "Expected 2, got " << Solution::findMinArrowShots({{{10, 16}, {2, 8}, {1, 6}, {7, 12}}}) << endl;
    cout << "Expected 4, got " << Solution::findMinArrowShots({{1, 2},
                                                               {3, 4},
                                                               {5, 6},
                                                               {7, 8}}) << endl;
    cout << "Expected 2, got " << Solution::findMinArrowShots({{1, 2},
                                                               {2, 3},
                                                               {3, 4},
                                                               {4, 5}}) << endl;
    cout << "Expected 1, got " << Solution::findMinArrowShots({{1, 2}}) << endl;
    cout << "Expected 1, got " << Solution::findMinArrowShots({{2, 3},
                                                               {2, 3}}) << endl;

}


