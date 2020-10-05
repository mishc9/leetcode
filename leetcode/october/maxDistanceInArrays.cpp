//
// Created by Михаил Степанов on 05.10.2020.
//

#include <vector>
#include <iostream>

using namespace std;
using Arrays = vector<vector<int>>;

class Array
{
    vector<int> array;
public:
    Array(const vector<int> &array) : array(array) {};

    int minVal() { return array.front(); }

    int maxVal() { return array.back(); }

    int nextToMinVal() { return array.size() == 1 ? array.back() : array[1]; };

    int nextToMaxVal() { return array.size() == 1 ? array.front() : array[array.size() - 2]; };
};

class Solution
{
public:
    static int maxDistance(const Arrays &arrays)
    {
        int result = 0;
        int min_val = arrays.front().front();
        int max_val = arrays.front().back();

        for (int it = 1; it < arrays.size(); it++) {
            auto item = arrays[it];
            result = max(result, max(abs(item.back() - min_val), abs(max_val - item.front())));
            min_val = min(min_val, item.front());
            max_val = max(max_val, item.back());
        }
        return result;
    }
};


int main()
{
    Array array({1, 2, 5});
    cout << array.minVal() << endl;
    cout << array.maxVal() << endl;
    cout << array.nextToMinVal() << endl;
    cout << array.nextToMaxVal() << endl;
}

