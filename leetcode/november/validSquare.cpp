//
// Created by Михаил Степанов on 11.11.2020.
//

#include <vector>
#include <cmath>

using namespace std;

class Solution
{
public:
    double distance(vector<int> &p1, vector<int> &p2)
    {
        return (p2[1] - p1[1]) * (p2[1] - p1[1]) + (p2[0] - p1[0]) * (p2[0] - p1[0]);
    }

    bool check(vector<int> &p1, vector<int> &p2, vector<int> &p3, vector<int> &p4)
    {
        return distance(p1, p2) > 0 && distance(p1, p2) == distance(p2, p3) && distance(p2, p3) == distance(p3, p4) &&
               distance(p3, p4) == distance(p4, p1) && distance(p1, p3) == distance(p2, p4);
    }

    bool validSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3, vector<int> &p4)
    {
        return check(p1, p2, p3, p4) ||
               check(p1, p3, p2, p4) ||
               check(p1, p2, p4, p3);
    }
};


class _Solution
{
public:
    bool validSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3, vector<int> &p4)
    {


        return false;
    }

    static bool tryValidSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3, vector<int> &p4)
    {
        bool eqLength = (length(p1, p2) == length(p2, p3) ==
                         length(p3, p4) == length(p4, p1));
        if (!eqLength) { return false; }
        bool isParallel = (testParallel(p1, p2, p3, p4) == testParallel(p1, p3, p2, p4));
        if (!isParallel) { return false; }
        return testNormality(p1, p2, p3);
    }

    static float length(vector<int> &p1, vector<int> &p2)
    {
        return sqrt(pow(float(p1[0]) - float(p2[0]), 2) +
                    pow(float(p1[1]) - float(p2[1]), 2));
    }

    static bool testParallel(vector<int> &p1, vector<int> &p2, vector<int> &p3, vector<int> &p4)
    {
        return ((p1[0] - p2[0]) == (p3[0] - p4[0])) and ((p1[1] - p2[1]) == (p3[1] - p4[1]));
    }

    static bool testNormality(vector<int> &p1, vector<int> &p2, vector<int> &p3)
    {
        int x1 = p1[0] - p2[0];
        int x2 = p1[0] - p3[0];
        int y1 = p1[1] - p2[1];
        int y2 = p1[1] - p3[1];

        return x1 * x2 + y1 * y2 == 0;
    }
};



