//
// Created by Михаил Степанов on 24.10.2020.
//

class ArrayReader
{
public:
    int get(int index) const;
};

class ArrayReader;

class Solution
{
public:
    int search(const ArrayReader &reader, int target)
    {
        if (reader.get(0) == target) { return 0; }

        int low = 0, high = 1;
        while (reader.get(high) < target) {
            low = high;
            high *= 2;
        }

        // It's unnecessary to find a strict upper bound
        int pivot, number;
        while (low <= high) {
            pivot = low + ((high - low) >> 1);
            number = reader.get(pivot);

            if (number == target) { return pivot; }
            if (number > target) { high = pivot - 1; }
            else { low = pivot + 1; }
        }
        return -1;
    }
};

