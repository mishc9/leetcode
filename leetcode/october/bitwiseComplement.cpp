//
// Created by Михаил Степанов on 05.10.2020.
//

#include <iostream>
#include <cmath>

using namespace std;

class Solution
{
public:
    static int _bitwiseComplement(int N)
    {
        if (N == 0) { return 1; }
        return int(pow(2, floor(log2(N)) + 1) - 1 - N);
    }

    static int bitwiseComplement(int N)
    {
        if (N == 0) { return 1; }
        int bitmask = N;
        bitmask |= (bitmask >> 1);
        bitmask |= (bitmask >> 2);
        bitmask |= (bitmask >> 4);
        bitmask |= (bitmask >> 8);
        bitmask |= (bitmask >> 16);
        return bitmask ^ N;
    }
};

int main()
{
    cout << "Expected 7, got " << Solution::bitwiseComplement(8) << endl;
    cout << "Expected 2, got " << Solution::bitwiseComplement(5) << endl;
    cout << "Expected 0, got " << Solution::bitwiseComplement(7) << endl;
    cout << "Expected 5, got " << Solution::bitwiseComplement(10) << endl;
    cout << "Expected 1, got " << Solution::bitwiseComplement(0) << endl;

    return 0;
}

