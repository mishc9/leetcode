//
// Created by Михаил Степанов on 1/23/21.
//

#include <vector>

using namespace std;


int main()
{

    return 0;
}

class CustomStack
{
    int _maxSize;
    vector<int> stack;

public:
    CustomStack(int maxSize) : _maxSize(maxSize) {}

    int pop()
    {
        int val = -1;
        if (!stack.empty()) {
            val = stack.back();
            stack.pop_back();
        }
        return val;
    }

    void push(int element)
    {
        if (stack.size() < _maxSize) {
            stack.emplace_back(element);
        }
    }

    void increment(int k, int val)
    {
        for (int i = 0; i < k && i < stack.size(); i++) {
            stack[i] += val;
        }
    }
};