//
// Created by Михаил Степанов on 26.08.2020.
//

#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;


int numOfSubarraySums(const vector<int> &array, int k)
{
    unordered_map<int, int> history;
    int count = 0;
    int currentSum = 0;
    history[0]++;
    for (auto val : array) {
        currentSum += val;
        if (history.count(currentSum - k) != 0) { count += history.at(currentSum - k); }
        history[currentSum]++;
    }
    return count;
}


int main()
{
    cout << numOfSubarraySums({3, 0, -1, 3, 5, -8, 2}, 0) << endl;
    cout << numOfSubarraySums({1, -1, 1, -1}, 0) << endl;
    cout << numOfSubarraySums({1, -1, 1, -1}, 0) << endl;
    cout << numOfSubarraySums({0, 0, 0, 0}, 0) << endl;
    cout << numOfSubarraySums({10, 2, -2, -20, 10}, -10) << endl;
    return 0;
}


