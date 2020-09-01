//
// Created by Михаил Степанов on 29.08.2020.
//

#include <vector>
#include <iostream>

using namespace std;


template<typename T>
ostream &operator<<(ostream &os, const vector<T> &vec)
{
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


class Solution
{
public:
    vector<int> pancakeSort(vector<int> &pancakes)
    {
        vector<int> ans;

        for (int valueToSort = pancakes.size(); valueToSort > 0; valueToSort--) {
            int index = distance(pancakes.begin(), find(pancakes.begin(), pancakes.end(), valueToSort));
            if (index == valueToSort - 1) { continue; }
            if (index != 0) {
                ans.emplace_back(index + 1);
                reverse(pancakes.begin(), pancakes.begin() + index + 1);
            }
            ans.emplace_back(valueToSort);
            reverse(pancakes.begin(), pancakes.begin() + valueToSort);
        }
        return ans;
    }
};

int main()
{
    Solution solution;

    vector<int> vec_3{3, 2, 1};
    solution.pancakeSort(vec_3);
    cout << vec_3 << endl;

    vector<int> vec_4{3, 2, 4, 1};
    solution.pancakeSort(vec_4);
    cout << vec_4 << endl;
    return 0;
}
