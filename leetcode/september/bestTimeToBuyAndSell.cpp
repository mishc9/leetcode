//
// Created by Михаил Степанов on 20.09.2020.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    static int maxProfit(const vector<int> &prices)
    {
        int profit = 0;
        if (prices.empty()) { return profit; }
        int minPrice = prices[0];
        for (int price : prices) {
            if (price < minPrice) {
                minPrice = price;
            }
            profit = max(profit, price - minPrice);
        }
        return profit;
    }
};

int main()
{
    cout << "Expected 5 got " << Solution::maxProfit({7, 1, 5, 3, 6, 4}) << endl;
    cout << "Expected 0 got " << Solution::maxProfit({7, 6, 4, 3, 1}) << endl;

    return 0;
}
