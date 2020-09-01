//
// Created by Михаил Степанов on 29.08.2020.
//

class Solution
{
public:
    int rand10()
    {
        int row, col, number;
        do {
            row = rand7();
            col = rand7();
            number = col + (row - 1) * 7;
        } while (number > 40);
        return (number - 1) % 10 + 1;
    }
};
