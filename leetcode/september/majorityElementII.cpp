//
// Created by Михаил Степанов on 22.09.2020.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    static vector<int> majorityElement(const vector<int> &nums)
    {
        int n1 = 0, n2 = 0;
        int c1 = 0, c2 = 0;
        vector<int> major;
        for (auto &&num: nums) {
            if (num == n1 && c1 != 0) {
                c1++;
                continue;
            }
            if (num == n2 && c2 != 0) {
                c2++;
                continue;
            }
            if (c1 == 0) {
                c1++;
                n1 = num;
                continue;
            }
            if (c2 == 0) {
                c2++;
                n2 = num;
                continue;
            }
            if (c1 > 0) {
                c1--;
            }
            if (c2 > 0) {
                c2--;
            }
        }
        // check n1 & n2
        int counter1 = 0, counter2 = 0;
        for (auto &&num: nums) {
            if (num == n1) {
                counter1++;
            } else if (num == n2) {
                counter2++;
            }
        }
        if (counter1 * 3 > nums.size()) {
            major.emplace_back(n1);
        }
        if (counter2 * 3 > nums.size()) {
            major.emplace_back(n2);
        }
        return major;
    }

    static int singleMajorityElement(const vector<int> &nums)
    {
        int count = 0;
        int candidate;
        for (auto num : nums) {
            if (count == 0) {
                candidate = num;
            }
            count += ((num == candidate) ? 1 : -1);
        }
        return candidate;
    }
};

template<typename T>
ostream &operator<<(ostream &os, const vector<T> &vec)
{
    bool first_element = true;
    os << '{';
    for (auto &value: vec) {
        if (first_element) {
            first_element = false;
            os << value;
            continue;
        }
        os << ", ";
        os << value;
    }
    os << '}';
    return os;
}

int main()
{
    cout << "Expected majority element is {3}, got " << Solution::majorityElement({3, 2, 3}) << endl;
    return 0;
}

