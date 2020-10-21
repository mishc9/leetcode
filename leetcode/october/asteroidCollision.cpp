//
// Created by Михаил Степанов on 21.10.2020.
//

#include <vector>
#include <iostream>
#include <stack>

using namespace std;


class Solution
{
public:
    static vector<int> asteroidCollision(vector<int> &a)
    {
        int n = a.size();
        vector<int> answer;
        for (int i = 0; i < n; i++) {
            while (!answer.empty() && a[i] < 0 && answer.back() > 0 && answer.back() < abs(a[i])) {
                answer.pop_back();
            }
            if (!answer.empty() && a[i] < 0 && answer.back() > 0 && answer.back() == abs(a[i])) {
                answer.pop_back();
                continue;
            }
            if (answer.empty() || answer.back() < 0 && a[i] < 0
                || answer.back() > 0 && a[i] > 0
                || answer.back() < 0 && a[i] > 0) {
                answer.push_back(a[i]);
            }
        }
        return answer;
    }
};


bool compare(const vector<int> &a, const vector<int> &b)
{
    if (a.size() != b.size()) { return false; }
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) { return false; }
    }
    return true;
}

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
    vector<pair<vector<int>, vector<int>>> cases = {
            {{8,  -8},       {}},
            {{5,  10, -5},   {5,  10}},
            {{10, 2,  -5},   {10}},
            {{-2, -1, 1, 2}, {-2, -1, 1, 2}},
    };


    for (auto[input_vector, gt_vector]: cases) {
        vector<int> result = Solution::asteroidCollision(input_vector);
        cout << "For input vector " << input_vector << " output vector is " << result
             << ", expected " << gt_vector << ", test " << (compare(gt_vector, result) ? "succeed" : "failed")
             << endl;
    }
    return 0;
}