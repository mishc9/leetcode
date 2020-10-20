//
// Created by Михаил Степанов on 16.10.2020.
//

#include <vector>

using namespace std;

class Solution
{
public:
    bool searchMatrix(const vector<vector<int>> &matrix, int target)
    {
        if (matrix.empty()) { return false; }

        int leftPtr = 0;
        int rightPtr = 1;
        int pivot;

        while (leftPtr <= rightPtr) {
            pivot = leftPtr + (rightPtr - leftPtr) / 2;
            if () {

            } else if (matrix[pivot][0] > target) {
                rightPtr = pivot - 1;
            } else {
                leftPtr = pivot + 1;
            }
        }

        return binarySearch(matrix[pivot], target);

    }
    bool binarySearch(const vector<int>& vec, int target) {

    }
};
