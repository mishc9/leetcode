//
// Created by Михаил Степанов on 26.10.2020.
//

#include <vector>

using namespace std;


class Solution
{
public:
    static double champagneTower(int poured, int query_row, int query_glass)
    {
        vector<vector<double>> tower(102, vector<double>(102, 0));

        tower[0][0] = poured;

        for (int row = 0; row < query_row; row++) {
            for (int column = 0; column <= row; column++) {
                double flow = (tower[row][column] - 1) / 2.0;

                if (flow > 0) {
                    tower[row + 1][column] += flow;
                    tower[row + 1][column + 1] += flow;
                }
            }
        }
        return min(1.0, tower[query_row][query_glass]);
    }
};