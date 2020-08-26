//
// Created by Михаил Степанов on 21.08.2020.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    static vector<int> sortArrayByParity(vector<int> &A)
    {
        if (A.empty()) { return A; }
        int evenPtr = 0;
        int oddPtr = A.size() - 1;

        while (evenPtr < oddPtr)
        {
            while (isEven(A[evenPtr]) && evenPtr < A.size() && evenPtr < oddPtr) { evenPtr++; }
            while (isOdd(A[oddPtr]) && oddPtr >= 0 && oddPtr > evenPtr) { oddPtr--; }
            if (evenPtr < oddPtr) { iter_swap(A.begin() + evenPtr, A.begin() + oddPtr); }
        }
        return A;
    }

    static bool isEven(int n) { return n % 2 == 0; }

    static bool isOdd(int n) { return n % 2; }

};

template<typename T>
ostream &operator<<(ostream &os, const vector<T> &vec)
{
    os << "[";
    bool first_step = true;
    for (auto val : vec)
    {
        if (first_step)
        {
            first_step = false;
            os << val;
            continue;
        }
        os << ", " << val;
    }
    os << "]";
    return os;
}

int main()
{
    Solution solution;
    vector<int> testInput{0, 2};
    cout << solution.sortArrayByParity(testInput) << endl;
    vector<int> testInputLong{2, 3, 7, 4, 8, 6, 1, 5, 9};
    cout << solution.sortArrayByParity(testInputLong) << endl;
    return 0;
}