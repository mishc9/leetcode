//
// Created by Михаил Степанов on 07.12.2020.
//


class Solution
{
public:
    static int minSteps(int n)
    {
        int answer = 0, divisor = 2;
        while (n > 1) {
            while (n % divisor == 0) {
                answer += divisor;
                n /= divisor;
            }
            divisor += 1;
        }
        return answer;
    }
};

#include <iostream>

using namespace std;

int main()
{
    cout << (Solution::minSteps(3) == 3) << endl;
    return 0;
}