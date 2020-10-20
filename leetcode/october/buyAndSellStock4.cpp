//
// Created by Михаил Степанов on 18.10.2020.
//

#include <vector>

using namespace std;


class Solution
{
public:
    static int maxProfit(int maxBuy, const vector<int> &prices)
    {
        int size = prices.size();
        if (size <= 0 || maxBuy <= 0) { return 0; }

        if (2 * maxBuy > size) {
            int result = 0;
            for (int i = 1; i < size; i++) { result += max(0, prices[i] - prices[i - 1]); }
            return result;
        }

        vector<vector<vector<int>>> table(size, vector<vector<int>>(maxBuy + 1, vector<int>(2, -1000000000)));

        table[0][0][0] = 0;
        table[0][1][1] = -prices[0];

        for (int i = 1; i < size; i++) {
            for (int j = 0; j <= maxBuy; j++) {
                table[i][j][0] = max(table[i - 1][j][0], table[i - 1][j][1] + prices[i]);
                if (j > 0) { table[i][j][1] = max(table[i - 1][j][1], table[i - 1][j - 1][0] - prices[i]); }
            }
        }

        int result = 0;
        for (int j = 0; j <= maxBuy; j++) {
            result = max(result, table[size - 1][j][0]);
        }
        return result;
    }
};

#include <iostream>

int main()
{
    cout << "Expected: 2, got : " << Solution::maxProfit(2, {2, 4, 1}) << endl;
    cout << "Expected: 7, got: " << Solution::maxProfit(2, {3, 2, 6, 5, 0, 3}) << endl;
    return 0;
}
