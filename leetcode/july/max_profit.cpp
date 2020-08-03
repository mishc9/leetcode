//
// Created by Михаил Степанов on 29.07.2020.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty()) { return 0; }
        if (prices.size() == 1) { return 0; }
        for (int i = 0; i < prices.size() - 1; i++) { prices[i] = prices[i + 1] - prices[i]; }
        prices.pop_back();

        return 0;
    }
};


int main() {
    Solution sol;
    vector<int> prices = {1, 2, 3, 0, 2};
    cout << sol.maxProfit(prices) << endl;
    return 0;
}
