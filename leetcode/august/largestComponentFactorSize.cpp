//
// Created by Михаил Степанов on 30.08.2020.
//

#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

using namespace std;


class _Solution
    // Brute force
{
public:
    int gcd(int a, int b)
    {
        while (a % b != 0) {
            int buf = a;
            a = b;
            b = buf % b;
        }
        return b;
    }

    int largestComponentSize(const vector<int> &array)
    {
        // Brute force
        queue<int> to_visit;
        unordered_set<int> candidates;
        int result = 0;
        for (int val : array) { candidates.insert(val); }


        while (!candidates.empty()) {
            int target = *candidates.begin();
            to_visit.push(target);
            candidates.erase(target);
            int localResult = 1;

            while (!to_visit.empty()) {
                int next = to_visit.front();
                to_visit.pop();
                for (auto val : candidates) {
                    if (gcd(val, next) > 1) {
                        to_visit.push(val);
                        localResult++;
                    }
                }
                int size = to_visit.size();
                for (int i = 0; i < size; i++) {
                    int front = to_visit.front();
                    to_visit.pop();
                    candidates.erase(front);
                    to_visit.push(front);
                }
            }
            result = max(localResult, result);
        }
        return result;
    }
};

class Solution
{
public:
    int parent[100001];

    int findAndUpdateRoot(int x)
    {
        if (parent[x] == -1) {
            return x;
        } else {
            parent[x] = find(parent[x]);
            return parent[x];
        }
    }

    inline void unite(int denominator, int numerator, int fraction)
    {
        int xParent = find(denominator);
        int yParent = find(numerator);
        if (xParent != yParent) { parent[yParent] = xParent; }

        yParent = find(numerator);
        int zParent = find(fraction);
        if (yParent != zParent) { parent[zParent] = yParent; }
    }

    int largestComponentSize(const vector<int> &arr)
    {
        unordered_map<int, int> memo;
        memset(parent, -1, sizeof(parent));
        int result = 0;
        for (int val : arr) {
            for (int divisor = 2; divisor * divisor <= val; ++divisor) {
                if (divisibleBy(val, divisor)) { unite(divisor, val, val / divisor); }
            }
        }
        for (int val : arr) {
            result = max(result, ++memo[find(val)]);
        }
        return result;
    }

    inline bool divisibleBy(int x, int i) { return x % i == 0; }
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
    vector<int> longVec{};
    return 0;
}
