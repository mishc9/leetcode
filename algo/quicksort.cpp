//
// Created by Михаил Степанов on 11.03.2020.
//
#include <vector>
#include <iostream>

using namespace std;

template<typename T>
void Swap(vector<T> &array, int i, int j);

template<typename T>
void Quicksort(vector<T> &array);

template<typename T>
void _Quicksort(vector<T> &array, int begin, int end);

template<typename T>
int Partition(vector<T> &array, int begin, int end);

template<typename T>
ostream &operator<<(ostream &stream, const vector<T> &array);

template<typename T>
void Swap(vector<T> &array, int i, int j) {
    T buff = array[i];
    array[i] = array[j];
    array[j] = buff;
}


template<typename T>
int Partition(vector<T> &array, int begin, int end) {
    // Lomuto partition
    T pivot_value = array[end];
    int i = begin;
    for (int j = begin; j < end; ++j) {
        if (array[j] < pivot_value) {
            // "drowning" a value under the "waterline" i
            Swap(array, i, j);
            // Increasing the "waterline"
            i++;
        }
    }
    Swap(array, i, end);
    return i;
}

template<typename T>
void Quicksort(vector<T> &array) {
    _Quicksort(array, 0, array.size() - 1);
}

template<typename T>
void _Quicksort(vector<T> &array, int begin, int end) {
    if (end - begin < 1) {
        return;
    }
    int pivot = Partition(array, begin, end);
    _Quicksort(array, begin, pivot - 1);
    _Quicksort(array, pivot + 1, end);
}

template<typename T>
ostream &operator<<(ostream &stream, const vector<T> &array) {
    for (const auto &val: array) {
        stream << val << ",";
    }
    return stream;
}

template<typename T>
bool IsIncreasingOrder(const vector<T> &array) {
    if (array.empty() || (array.size() == 1)) {
        return true;
    } else {
        for (int i = 1; i < array.size(); ++i) {
            if (array[i - 1] > array[i]) {
                return false;
            }
        }
        return true;
    }
}

void _VectorFromDecimal(int value, vector<int> &permutation) {
    int part = value / 10;
    int residual = value % 10;

    if (part == 0) {
        permutation.emplace_back(residual);
        return;
    }
    _VectorFromDecimal(part, permutation);
    permutation.emplace_back(residual);
}

vector<int> VectorFromDecimal(int value) {
    vector<int> permutation;
    _VectorFromDecimal(value, permutation);
    return permutation;
}

void TestAllCombinations(int from, int to) {
    // Over-complicated but full-cover test;
    vector<int> combinations, copy_;
    for (int value = from; value < to; ++value) {
        combinations = VectorFromDecimal(value);
        copy_ = VectorFromDecimal(value);
        Quicksort(combinations);
        if (IsIncreasingOrder(combinations) != 1) {
            cerr << "Combination " << copy_ << " was not sorted: "
            << combinations << endl;
        }
    }
}


int main() {
    vector<int> array = {};
    Quicksort(array);
    assert(IsIncreasingOrder(array));
    TestAllCombinations(0, 10000);
}
