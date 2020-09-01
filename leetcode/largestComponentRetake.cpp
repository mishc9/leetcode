//
// Created by Михаил Степанов on 31.08.2020.
//

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;


class Solution
{
    vector<int> commonDivisors;  // I'm not sure if the name is good enough

public:
    void groupDivisors(int denominator, int numerator, int fraction)
    {

        int denomParent, numParent, fracParent;
        denomParent = findAndUpdateRoot(denominator);
        numParent = findAndUpdateRoot(numerator);
        if (numParent != denomParent) { commonDivisors[numParent] = denomParent; }
        numParent = findAndUpdateRoot(numerator);
        fracParent = findAndUpdateRoot(fraction);
        if (numParent != fracParent) { commonDivisors[fracParent] = numParent; }
    }

    int largestComponentSize(const vector<int> &array)
    {
        int size = 100001;
        commonDivisors.reserve(size);
        commonDivisors.clear();
        for (int i = 0; i < size; i++) { commonDivisors.emplace_back(-1); }
        int result = 0;
        unordered_map<int, int> counts;
        for (auto val: array) {
            for (int i = 2; i * i <= val; i++) {
                if (val % i == 0) {
                    groupDivisors(i, val, val / i);
                }
            }
        }

        for (auto val: array) { result = max(result, ++counts[findAndUpdateRoot(val)]); }

        return result;
    }

    int findAndUpdateRoot(int x)
    {
        if (commonDivisors[x] == -1) {
            return x;
        } else {
            commonDivisors[x] = findAndUpdateRoot(commonDivisors[x]);
            return commonDivisors[x];
        }
    }


};


int main()
{
    Solution solution;
    cout << (solution.largestComponentSize({2, 3, 6, 7, 4, 12, 21, 39}) == 8) << endl;
    cout << solution.largestComponentSize({2, 3, 6, 7, 4, 12, 21, 39}) << endl;

    cout << (solution.largestComponentSize({20, 50, 9, 63}) == 2) << endl;
    cout << solution.largestComponentSize({20, 50, 9, 63}) << endl;

    cout << (solution.largestComponentSize({4, 6, 15, 35}) == 4) << endl;
    cout << solution.largestComponentSize({4, 6, 15, 35}) << endl;

    return 0;
}