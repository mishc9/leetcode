//
// Created by Михаил Степанов on 16.08.2020.
//


#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

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


class Solution {
public:
    int maxProfitDP(vector<int> &prices) {
        int length = prices.size();
        if (length <= 1) return 0;

        int leftMin = prices[0];
        int rightMax = prices[length - 1];

        // allocate left and right
        vector<int> leftProfits(length, 0);
        vector<int> rightProfits(length + 1, 0);

        // Make left index and right index simultaneously
        for (int lIndex = 1; lIndex < length; ++lIndex) {
            leftProfits[lIndex] = max(leftProfits[lIndex - 1], prices[lIndex] - leftMin);
            leftMin = min(leftMin, prices[lIndex]);

            int rIndex = length - 1 - lIndex;
            rightProfits[rIndex] = max(rightProfits[rIndex + 1], rightMax - prices[rIndex]);
            rightMax = max(rightMax, prices[rIndex]);
        }

        int maxProfit = 0;
        for (int index = 0; index < length; ++index) {
            maxProfit = max(maxProfit, leftProfits[index] + rightProfits[index + 1]);
        }
        return maxProfit;
    }


    int maxProfit(vector<int> &prices) {
        int t1Cost = INT_MAX,
                t2Cost = INT_MAX;
        int t1Profit = 0,
                t2Profit = 0;

        for (int price : prices) {
            // the maximum profit if only one transaction is allowed
            t1Cost = min(t1Cost, price);
            t1Profit = max(t1Profit, price - t1Cost);
            // re-invest the gained profit in the second transaction
            t2Cost = min(t2Cost, price - t1Profit);
            t2Profit = max(t2Profit, price - t2Cost);
        }

        return t2Profit;
    }
};


int main() {
    Solution solution;

    struct Case {
        vector<int> prices;
        int profit;
    };
    vector<Case> testCases{{{7, 1, 5, 3, 6, 4},       7},
                           {{3, 3, 5, 0, 0, 3, 1, 4}, 6},
                           {{1, 2, 3, 4, 5},          4},
                           {{7, 6, 4, 3, 1},          0}
    };

    for (auto &[prices, profit]: testCases) {
        cout << (solution.maxProfit(prices) == profit) << endl;
        cout << (solution.maxProfitDP(prices) == profit) << endl;

    }
    return 0;
}
