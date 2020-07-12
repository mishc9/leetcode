//
// Created by Михаил Степанов on 11.07.2020.
//


#include <vector>
#include <iostream>

using namespace std;


template<typename T>
ostream &operator<<(ostream &os, const vector<T> vec) {
    cout << "[";
    for (auto &val :vec) {
        os << val << ", ";
    }
    cout << "]";
    return os;
}

class Solution {
public:
    void removeZeros(vector<int> &arr) {
        if (arr.empty()) return;

        int copy_to = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] != 0) {
                arr[copy_to] = arr[i];
                copy_to++;
            }
        }
        arr.resize(copy_to);
    }

    void removeDuplicatedZeros(vector<int> &arr) {
        if (arr.empty()) return;

        int copy_to = 0;
        bool previousZero = false;
        for (int i = 0; i < arr.size(); i++) {
            arr[copy_to] = arr[i];
            if (arr[i] != 0) {  // if (arr[i] != 0 and !previousZero) {
                arr[copy_to] = arr[i];
                previousZero = false;
                copy_to++;
                continue;
            }
            // if (arr[i] != 0 and !previousZero) {
            //     arr[copy_to] = arr[i];
            //     copy_to++;
            //     continue;
            // }
            // if (arr[i] == 0 and previousZero) {
            //     continue;
            // }
            if (arr[i] == 0 and !previousZero) {
                previousZero = true;
                arr[copy_to] = arr[i];
                copy_to++;
                continue;
            }
        }
        arr.resize(copy_to);
    }

    void duplicateZeros(vector<int> &arr) {
        if (arr.empty()) { return; }
        int zeroCount = 0;
        for (auto val: arr) { if (val == 0) { zeroCount++; }}
        if (!zeroCount) { return; }
        arr.resize(arr.size() + zeroCount);
        int copyTo = arr.size() - 1;
        for (int copyFrom = arr.size() - 1 - zeroCount; copyFrom >= 0; copyFrom--) {
            arr[copyTo--] = arr[copyFrom];
            if (arr[copyFrom] == 0) { arr[copyTo--] = arr[copyFrom]; }
        }
        // If we don't need tails we can avoid resizing array twice. Just count when you're out of array then stop.
        arr.resize(arr.size() - zeroCount);
    }

    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        int lPtr = 0;
        int rPtr = 0;
        int tPtr = 0;
        // Iterate through all elements of ar2[] starting from
        // the last element
        for (int i = n - 1; i >= 0; i--) {
            /* Find the smallest element greater than ar2[i]. Move all
               elements one position ahead till the smallest greater
               element is not found */
            int j, last = nums1[m - 1];
            for (j = m - 2; j >= 0 && nums1[j] > nums2[i]; j--)
                nums1[j + 1] = nums1[j];

            // If there was a greater element
            if (j != m - 2 || last > nums2[i]) {
                nums1[j + 1] = nums2[i];
                nums2[i] = last;
            }
        }
    }
};


int main() {
    Solution sol;
    vector<int> vec{1, 0, 2, 3, 0, 4, 5};
    sol.removeZeros(vec);
    cout << vec << endl;
    vector<int> vecDup{1, 0, 0, 2, 3, 0, 0, 4, 5, 0};
    sol.removeDuplicatedZeros(vecDup);
    cout << vecDup << endl;
    vector<int> zeros(10, 0);
    sol.removeDuplicatedZeros(zeros);
    cout << zeros << endl;
    vector<int> toDup{1, 2, 3, 0, 0, 4, 5, 0, 0, 0, 6};
    sol.duplicateZeros(toDup);
    cout << toDup << endl;
    vector<int> toDup2{1, 2, 3, 0, 0, 4, 5, 0, 0, 0, 6, 0};
    sol.duplicateZeros(toDup2);
    cout << toDup2 << endl;
    return 0;
}
