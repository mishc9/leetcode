//
// Created by Михаил Степанов on 15.10.2020.
//

#include <vector>

using namespace std;

class _Solution
{
public:
    static void rotate(vector<int> &nums, int k)
    {
        k %= nums.size();
        int moveFor = k;
        if (moveFor == 0) { return; }

        int moveFrom = 0;

        for (int nMoved = 0; nMoved != nums.size(); nMoved++) {
            int buff = nums[moveFor];
            nums[moveFor] = nums[0];
            nums[0] = buff;
            moveFor += k;
            moveFor %= nums.size();
            if (moveFor == 0) {

            }
        }
    }
};

class Solution
{
public:
    static void rotate(vector<int> &nums, int k)
    {
        k %= nums.size();
        int count = 0;
        for (int moveFrom = 0; count < nums.size(); moveFrom++) {
            int currentMoveFrom = moveFrom;
            int previous = nums[moveFrom];
            do {
                int next = (currentMoveFrom + k) % nums.size();
                int buff = nums[next];
                nums[next] = previous;
                previous = buff;
                currentMoveFrom = next;
                count++;
            } while (moveFrom != currentMoveFrom);
        }
    }

    static void rotateByReverse(vector<int> &nums, int k)
    {
        k %= nums.size();
        if (k == 0) { return; }
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

#include <iostream>

int main()
{
    vector<vector<int>> vecs{{1,  2,    3, 4, 5},
                             {-1, -100, 3, 99}};
    for (auto &vec: vecs) {
        Solution::rotate(vec, 2);
        for (auto v: vec) { cout << v << " "; }
        cout << endl;
    }
    vecs = {{1,  2,    3, 4, 5},
            {-1, -100, 3, 99}};
    for (auto &vec: vecs) {
        Solution::rotateByReverse(vec, 2);
        for (auto v: vec) { cout << v << " "; }
        cout << endl;
    }
    return 0;
}
