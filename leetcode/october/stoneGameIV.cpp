//
// Created by Михаил Степанов on 25.10.2020.
//

#include <vector>

using namespace std;

class Solution
{
public:
    bool winnerSquareGame(int n)
    {
        vector<bool> memory(n + 1);
        for (int i = 0; i <= n; i++) {
            if (memory[i]) { continue; }
            for (int k = 1; i + k * k <= n; k++) { memory[i + k * k] = true; }
        }
        return memory[n];
    }
};
