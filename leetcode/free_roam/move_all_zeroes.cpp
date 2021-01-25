//
// Created by Михаил Степанов on 1/18/21.
//

#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void move_zeroes_left(vector<T> &vec)
{
    int right = vec.size() - 1;
    for (int left = right; left >= 0; --left) {
        if (vec[left] != 0) { vec[right--] = vec[left]; }
    }
    for (int i = right; i >= 0; --i) { vec[i] = 0; }
}

template<typename T>
void move_zeroes_right(vector<T> &vec)
{
    int left = 0;
    for (int right = left; right < vec.size(); right++) {
        if (vec[right] != 0) { vec[left++] = vec[right]; }
    }
    for (int i = left; i < vec.size(); i++) { vec[i] = 0; }
}

template<typename T>
ostream &operator<<(ostream &os, vector<T> vec)
{

    bool first = true;
    os << "[";

    for (auto &val : vec) {
        if (first) {
            os << val;
            first = false;
            continue;
        }
        os << ", " << val;
    }
    os << "]";
    return os;
}

int main()
{
    vector<int> vec{1, 2, 3, 0, 0, 4, 5, 0, 0, 0, 6, 0, 7, 8, 0};
    move_zeroes_left(vec);
    cout << vec << endl;

    vec = {1, 2, 3, 0, 0, 4, 5, 0, 0, 0, 6, 0, 7, 8, 0};
    move_zeroes_right(vec);
    cout << vec << endl;
    return 0;
}

