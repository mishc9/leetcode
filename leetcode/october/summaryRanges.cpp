//
// Created by Михаил Степанов on 29.10.2020.
//


#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> result;
        int num, i = 0;

        while (i < nums.size()) {
            num = nums[i++];
            int buff = num;
            string ans = to_string(num);
            while (i < nums.size() && num + 1 == nums[i]) { num = nums[i++]; }
            result.push_back(buff != num ? ans + "->" + to_string(num) : ans);
        }
        return result;
    }
};
