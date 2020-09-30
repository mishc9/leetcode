//
// Created by Михаил Степанов on 06.09.2020.
//

#include <vector>
#include <iostream>

using namespace std;

template<typename T>
ostream &operator<<(ostream &os, const vector<T> &vec)
{
    os << "[";
    bool firstStep = true;

    for (const auto &val: vec) {
        if (firstStep) {
            os << val;
            firstStep = false;
            continue;
        }
        os << ", " << val;
    }

    os << "];";
    return os;
}

class Solution
{
public:
    int largestOverlap(const vector<vector<int>> &A, const vector<vector<int>> &B)
    {
        vector<int> a_horizontal, a_vertical, b_horizontal, b_vertical;
        int overlap = 0;

        a_horizontal = horizontalSum(A);
        a_vertical = verticalSum(A);

        b_horizontal = horizontalSum(B);
        b_vertical = verticalSum(B);

        int horizontal_shift = alignTwoVectors(a_horizontal, b_horizontal);
        int vertical_shift = alignTwoVectors(a_vertical, b_vertical);


        return overlap;
    }

    static vector<int> verticalSum(const vector<vector<int>> &array)
    {
        vector<int> result;
        for (int nRow = 0; nRow < array.size(); nRow++) {
            int sum = 0;
            for (int nCol = 0; nCol < array[nRow].size(); nCol++) {
                sum += array[nCol][nRow];
            }
            result.emplace_back(sum);
        }
        return result;
    }

    static vector<int> horizontalSum(const vector<vector<int>> &array)
    {
        vector<int> result;
        if (array.empty()) { return result; }
        for (int nCol = 0; nCol < array[0].size(); nCol++) {
            int sum = 0;
            for (int nRow = 0; nRow < array[nCol].size(); nRow++) {
                sum += array[nCol][nRow];
            }
            result.emplace_back(sum);
        }
        return result;
    }

    int alignTwoVectors(const vector<int> &a, const vector<int> &b)
    {
        vector<int> tmp;
        tmp = a;
        int minDiff = 0;
        int minShift = 0;
        for (int i = 0; i < a.size(); i++) {
            int totalDiff = 0;
            for (int j = i; j < b.size(); j++) {
                totalDiff += abs(a[j] - b[i]);
            }
            if (totalDiff < minDiff) {
                minDiff = totalDiff;
                minShift = i;
            }
        }
        for (int i = a.size() - 1; i >= 0; i--) {
            int totalDiff = 0;
            for (int j = i; j >= 0; j--) {
                totalDiff += abs(a[j] - b[i]);
            }
            if (totalDiff < minDiff) {
                minDiff = totalDiff;
                minShift = i - a.size();
            }
        }
        return minShift;
    }

    int compareShifted(const vector<vector<int>> A, const vector<vector<int>> B, int h_shift, int v_shift)
    {
        int overlap = 0;
        if (v_shift > 0) {
            for (int i = 0; i + v_shift < A.size(); i++) {
                if (h_shift > 0) {
                    for (int j = 0; j + h_shift < B.size(); j++) {
                        overlap += (A[i + v_shift][j + h_shift] == 1) && (B[i][j] == 1);
                    }
                } else {
                    for (int j = ; j + h_shift < B.size(); j++) {
                        overlap += (A[i + v_shift][j + h_shift] == 1) && (B[i][j] == 1);
                    }
                }
            }
        }
        return overlap;
    }
};


int main()
{
    Solution solution;
    vector<vector<int>> array{{1, 1, 0},
                              {0, 1, 0},
                              {0, 1, 1}};
    vector<vector<int>> barray{{0, 0, 0},
                               {0, 1, 1},
                               {0, 0, 1}};
    cout << solution.horizontalSum(array) << endl;
    cout << solution.verticalSum(array) << endl;
    cout << solution.largestOverlap(array, barray) << endl;
    return 0;
}
