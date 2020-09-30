//
// Created by Михаил Степанов on 15.09.2020.
//

#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    static int lengthOfLastWord(const string &text)
    {
        // if (text.empty()) { throw runtime_error("Empty string as input"); }
        int result = 0;
        if (text.empty()) { return result; }
        auto begin = text.begin();
        auto ptr = text.end();
        ptr--;

        while (*ptr == ' ' && ptr >= begin) {
            ptr--;
        }
        int counter;
        for (counter = 0; ptr >= begin; ptr--, counter++) {
            if (*ptr == ' ') { break; }
        }
        return counter;
    }
};

int main()
{
    cout << Solution::lengthOfLastWord("Hello world") << endl;
    cout << Solution::lengthOfLastWord("Hello world    ") << endl;
    cout << Solution::lengthOfLastWord("world    ") << endl;
    cout << Solution::lengthOfLastWord("    ") << endl;
    cout << Solution::lengthOfLastWord("") << endl;
    return 0;
}
