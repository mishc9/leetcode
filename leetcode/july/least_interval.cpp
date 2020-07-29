//
// Created by Михаил Степанов on 28.07.2020.
//

#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;


class Solution {
public:
    int count[26], maxcnt = 0, extend = 0;

    int leastInterval(const vector<char> &tasks, int n) {
        // count how frequent each element is
        for (char value : tasks) { count[value - 'A']++; }
        // find maximal count. It will be an element which determines "slowness" of the calculation
        for (int i : count) { maxcnt = max(maxcnt, i); }
        // find if there are more elements with max count, and if exists, how many
        for (int i : count) { if (i == maxcnt) { extend++; }}
        return max(int(tasks.size()), (maxcnt - 1) * (n + 1) + extend);
    }
};


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


int main() {
    Solution sol;
    cout << sol.leastInterval({'A', 'A', 'A', 'B', 'B', 'B'}, 2) << endl;
    return 0;
}