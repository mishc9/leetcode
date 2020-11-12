//
// Created by Михаил Степанов on 10.11.2020.
//

#include <vector>

using namespace std;

class Solution
{
public:
    static vector<vector<int>> flipAndInvertImage(vector<vector<int>> &image)
    {
        int size = image[0].size();
        for (auto &row: image)
            for (int i = 0; i < (size + 1) / 2; ++i) {
                int tmp = row[i] ^ 1;
                row[i] = row[size - 1 - i] ^ 1;
                row[size - 1 - i] = tmp;
            }
        return image;
    }
};

