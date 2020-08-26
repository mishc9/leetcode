//
// Created by Михаил Степанов on 09.08.2020.
//

#include <vector>
#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <stack>

using namespace std;


template<typename T>
vector<size_t> indexSort(const vector<T> &v) {
    // initialize original index locations
    vector<size_t> idx(v.size());
    iota(idx.begin(), idx.end(), 0);

    // sort indexes based on comparing values in v
    // using std::stable_sort instead of std::sort
    // to avoid unnecessary index re-orderings
    // when v contains elements of equal values
    stable_sort(idx.begin(), idx.end(), [&v](size_t i1, size_t i2) { return v[i1] < v[i2]; });

    return idx;
}


class Solution {
public:
    int oddEvenJumps(vector<int> &array) {
        vector<int> argSorted;
        argSorted.reserve(array.size());
        for (int i = 0; i < array.size(); i++) { argSorted.emplace_back(i); }
        stable_sort(argSorted.begin(), argSorted.end(),
                    [&array](int i1, int i2) { return array[i1] < array[i2]; });

        vector<int> oddNext(array.size(), -1);
        vector<int> evenNext(array.size(), -1);
        stack<int> stack;

        for (int ordStatistic : argSorted) {
            while (!stack.empty() && ordStatistic > stack.top()) {
                int tos = stack.top();
                stack.pop();
                oddNext[tos] = ordStatistic;
            }
            stack.push(ordStatistic);
        }

        for (int i = 0; i < array.size(); i++) { argSorted[i] = i; }
        stable_sort(argSorted.begin(), argSorted.end(),
                    [&array](int i1, int i2) { return array[i1] > array[i2]; });

        while (!stack.empty()) { stack.pop(); }

        for (int ordStatistic : argSorted) {
            while (!stack.empty() && ordStatistic > stack.top()) {
                int tos = stack.top();
                stack.pop();
                evenNext[tos] = ordStatistic;
            }
            stack.push(ordStatistic);
        }

        vector<int> odd(array.size(), 0);
        vector<int> even(array.size(), 0);

        odd[odd.size() - 1] = 1;
        even[even.size() - 1] = 1;

        for (int i = array.size() - 2; i >= 0; i--) {
            if (oddNext[i] != -1) { odd[i] = even[oddNext[i]]; }
            if (evenNext[i] != -1) { even[i] = odd[evenNext[i]]; }
        }
        int result = 0;
        for (auto val: odd) { result += val; }
        return result;
    }
};


int main() {
    Solution solution;

    vector<int> vec0{10};
    cout << (solution.oddEvenJumps(vec0) == 1) << endl;
    vector<int> vec1{10, 13, 12, 14, 15};
    cout << (solution.oddEvenJumps(vec1) == 2) << endl;
    vector<int> vec2{2, 3, 1, 1, 4};
    cout << (solution.oddEvenJumps(vec2) == 3) << endl;
    vector<int> vec3{5, 1, 3, 4, 2};
    cout << (solution.oddEvenJumps(vec3) == 3) << endl;
    vector<int> vec4{1, 2, 3, 2, 1, 4, 4, 5};
    cout << (solution.oddEvenJumps(vec4) == 6) << endl;
}
