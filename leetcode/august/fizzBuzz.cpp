//
// Created by Михаил Степанов on 26.08.2020.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution
{
public:
    vector<string> fizzBuzz(int n)
    {
        vector<string> result(n);
        for (int i = 1; i < n + 1; i++) {
            string now;
            if (i % 3 == 0) { now += "Fizz"; }
            if (i % 5 == 0) { now += "Buzz"; }
            if (now.empty()) { now = to_string(i); }
            result[i - 1] = now;
        }

        return result;
    }

    vector<string> _fizzBuzz(int n)
    {
        vector<string> result(n);
        for (int i = 1; i <= n; i++) { result[i - 1] = fizzBuzzForN(i); }
        return result;
    }

    static string fizzBuzzForN(int n)
    {
        string answer;
        if (n % 15 == 0) { answer = "FizzBuzz"; }
        else if (n % 3 == 0) { answer = "Fizz"; }
        else if (n % 5 == 0) { answer = "Buzz"; }
        else { answer = to_string(n); }
        return answer;
    }
};

template<typename T>
ostream &operator<<(ostream &os, vector<T> vec)
{
    bool firstItem = true;
    cout << "[";
    for (auto &val : vec) {
        if (firstItem) {
            cout << val;
            firstItem = false;
        } else {
            cout << ", " << val;
        }
    }
    cout << "]";
    return os;
}

int main()
{
    Solution solution;

    cout << solution.fizzBuzz(15) << endl;
    cout << solution._fizzBuzz(15) << endl;

    return 0;
}