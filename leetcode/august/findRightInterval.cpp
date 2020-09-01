//
// Created by Михаил Степанов on 27.08.2020.
//

#include <iostream>
#include <vector>
#include <numeric>      // std::iota
#include <algorithm>

using namespace std;

using interval = vector<int>;
using Intervals = vector<interval>;

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


class _Solution {
    struct {
        bool operator()(interval l, interval r) { return l[1] < r[1]; }
    } comp;

public:
    vector<int> findRightInterval(Intervals &intervals) {
        vector<int> index(intervals.size());
        iota(index.begin(), index.end(), 0);
        stable_sort(index.begin(), index.end(),
                    [&intervals](int i, int j) { return intervals[i][1] < intervals[j][1]; });
        cout << index << endl;
        return index;
    }
};

class Solution {
public:
    interval findRightInterval(Intervals &intervals) {
        int len = intervals.size();
        vector<int> res(len);
        pair<int, int> pos[len];
        auto endOfPos = pos + len;

        for (int i = 0; i < len; i++) {
            pos[i] = {intervals[i][0], i};
        }
        sort(pos, endOfPos);

        for (int i = 0; i < len; i++) {
            auto p = lower_bound(
                    pos, endOfPos,
                    intervals[i][1], [](auto it, int val) { return it.first < val; }
            );
            res[i] = p == endOfPos ? -1 : p->second;
        }
        return res;
    }
};


int main() {
    Solution solution;

    Intervals intervals{{0, 2},
                        {0, 1},
                        {0, 0}};
    Intervals intervals_2{{0, 1},
                          {0, 2},
                          {0, 0}};
    solution.findRightInterval(intervals);
    solution.findRightInterval(intervals_2);

    return 0;
}
