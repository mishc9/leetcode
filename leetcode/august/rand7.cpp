//
// Created by Михаил Степанов on 28.08.2020.
//

class Solution {
public:
    int rand10(void) {
        int rows, cols, number;

        rows = rand7() - 1;
        do {
            cols = rows;
            rows = rand7() - 1;
            number = rows * 7 + cols;
        } while (number > 39);

        return number % 10 + 1;
    }
};

