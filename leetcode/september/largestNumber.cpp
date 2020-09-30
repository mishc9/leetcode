//
// Created by Михаил Степанов on 25.09.2020.
//

#include <vector>
#include <string>
#include <iostream>

using namespace std;


class Solution
{
public:
    static string largestNumber(vector<int> &nums)
    {
        struct
        {
            bool operator()(int lhs, int rhs)
            {
                return to_string(lhs) + to_string(rhs) > to_string(rhs) + to_string(lhs);
            }
        } comp;
        sort(nums.begin(), nums.end(), comp);
        string answer;
        for (auto num : nums) { answer.append(to_string(num)); }
        if (
                !answer.empty()
                && std::adjacent_find(answer.begin(), answer.end(), std::not_equal_to<>()) == answer.end()
                && answer[0] == '0'
                ) {
            return "0";
        }
        return answer;
    }
};

int main()
{
    vector<int> vec = {10, 2};
    cout << "210 " << Solution::largestNumber(vec) << endl;
    vector<int> vec2 = {3, 30, 34, 5, 9};
    cout << "9534330 " << Solution::largestNumber(vec2) << endl;
    vector<int> vec3 = {0, 0};
    cout << "00 " << Solution::largestNumber(vec3) << endl;
    return 0;
}
