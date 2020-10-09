//
// Created by Михаил Степанов on 08.10.2020.
//

#include <vector>

using namespace std;

class Solution {
public:
    static int search(const vector<int>& numbers, int target) {
        int pivot;
        int leftPtr = 0;
        int rightPtr = numbers.size() - 1;
        while (leftPtr <= rightPtr) {
            pivot = leftPtr + (rightPtr - leftPtr) / 2;
            if (numbers[pivot] == target) {
                return pivot ;
            }
            if (target < numbers[pivot]) { rightPtr = pivot - 1 ; }
            else { leftPtr = pivot + 1; }
        }
        return -1;
    }
};
