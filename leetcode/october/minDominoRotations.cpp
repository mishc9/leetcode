//
// Created by Михаил Степанов on 19.10.2020.
//

#include <vector>

using namespace std;

class Solution
{
public:
    static int _minDominoRotations(vector<int> &A, vector<int> &B)
    {
        if (A.empty() and B.empty()) { return -1; }
        int num;
        int counts = 0;
        for (auto val: A) {
            if (counts == 0) {
                num = val;
                counts++;
            } else if (val == num) { counts++; }
            else { counts--; }
        }
        for (auto val: B) {
            if (counts == 0) {
                num = val;
                counts++;
            } else if (val == num) { counts++; }
            else { counts--; }
        }
        int countsA = 0;
        int countsB = 0;
        int totalCounts = 0;
        for (int i = 0; i < A.size(); i++) {
            if (A[i] == num) { countsA++; }
            if (B[i] == num) { countsB++; }
            if (A[i] == num or B[i] == num and A[i] != B[i]) { totalCounts++; }
        }
        if (totalCounts < A.size()) { return -1; }

        if (countsA > countsB) {
            for (int i = 0; i < A.size(); i++) {
                if (A[i] == 0) {
                    int buff = A[i];
                    A[i] = B[i];
                    B[i] = buff;
                }
            }
        } else {
            for (int i = 0; i < A.size(); i++) {
                if (B[i] == 0) {
                    int buff = A[i];
                    A[i] = B[i];
                    B[i] = buff;
                }
            }
        }
        return num;
    }
    static int minDominoRotations(vector<int> &A, vector<int> &B)
    {
        if (A.empty() and B.empty()) { return -1; }
        int num;
        int counts = 0;
        for (auto val: A) {
            if (counts == 0) {
                num = val;
                counts++;
            } else if (val == num) { counts++; }
            else { counts--; }
        }
        for (auto val: B) {
            if (counts == 0) {
                num = val;
                counts++;
            } else if (val == num) { counts++; }
            else { counts--; }
        }
        int countsA = 0;
        int countsB = 0;
        int totalCounts = 0;
        for (int i = 0; i < A.size(); i++) {
            if (A[i] == num and A[i] != B[i]) { countsA++; }
            if (B[i] == num and A[i] != B[i]) { countsB++; }
            if (A[i] == num or B[i] == num and A[i] != B[i]) { totalCounts++; }
        }
        if (totalCounts < A.size()) { return -1; }
        return min(countsB, countsA);
    }
};

#include <iostream>

int main()
{
    vector<int> A = {2, 1, 2, 4, 2, 2}, B = {5, 2, 6, 2, 3, 2};
    cout << "Expected: 2, got " << Solution::minDominoRotations(A, B) << endl;
    A = {3, 5, 1, 2, 3}, B = {3, 6, 3, 3, 4};
    cout << "Expected: -1, got " << Solution::minDominoRotations(A, B) << endl;

    return 0;
}
