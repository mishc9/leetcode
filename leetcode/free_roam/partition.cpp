//
// Created by Михаил Степанов on 30.12.2020.
//

#include <vector>

using namespace std;

class Solution
{
    static int arrayPairSum(vector<int> &nums)
    {
        vector<int> arr(20001);
        int lim = 10000;
        for (int &num: nums) { arr[num + lim]++; }
        int d = 0, sum = 0;
        for (int i = -10000; i <= 10000; i++) {
            sum += (arr[i + lim] + 1 - d) / 2 * i;
            d = (2 + arr[i + lim] - d) % 2;  // if there's one more value of this item
        }
        return sum;
    }
};


int main()
{

    return 0;
}