//
// Created by Михаил Степанов on 03.11.2020.
//

#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    static int maxPower(const string &string)
    {
        int count = 0;
        int maxCount = 0;
        char previous = ' ';
        for (char character : string) {
            if (character == previous) { count++; }
            else {
                count = 1;
                previous = character;
            }
            maxCount = max(maxCount, count);
        }
        return maxCount;
    }
};
