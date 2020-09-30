//
// Created by Михаил Степанов on 08.09.2020.
//

#include <deque>
#include <iostream>

using namespace std;

class MovingAverage
{
public:
    /** Initialize your data structure here. */
    MovingAverage(int size)
    {
        this->size = size;
    }

    double next(int val)
    {
        integerDeque.push_back(val);
        if (integerDeque.size() > size) { integerDeque.pop_front(); }
        int queueSum = 0;
        for (int &it : integerDeque) {
            queueSum += it;
        }
        return (double) queueSum / min((int) integerDeque.size(), (int) size);
    }

public:
    deque<int> integerDeque;
    int size;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */

int main()
{
    MovingAverage movingAverage(3);
    cout << movingAverage.next(1) << endl;
    cout << movingAverage.next(10) << endl;
    cout << movingAverage.next(3) << endl;
    cout << movingAverage.next(5) << endl;
}
