//
// Created by Михаил Степанов on 25.07.2020.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int findMin(const vector<int> &v) {
        if (v.empty()) { return 0; }
        if (v.size() == 1) { return v[0]; }
        int minVal = v[0];
        for (int i = 1; i < v.size(); i++) {
            if (v[i] < minVal) {
                return v[i];
            }
        }
        return minVal;
    }

    int findMinBisect(const vector<int> &v) {
        if (v.empty()) { return 0; }
        if (v.size() == 1) { return v[0]; }
        int leftPtr = 0;
        int rightPtr = v.size() - 1;

    }
};

template<typename T>
ostream &operator<<(ostream &os, const vector<T> v) {
    bool firstStep = true;
    cout << "[";
    for (const auto &val : v) {
        if (firstStep) {
            cout << val;
            firstStep = false;
            continue;
        }
        cout << ", " << val;
    }
    cout << "]";
    return os;
}


int main() {
    Solution sol;
    cout << sol.findMin({2, 2, 2, 0, 1}) << endl;
    cout << sol.findMin({1, 3, 5}) << endl;

    return 0;

}
