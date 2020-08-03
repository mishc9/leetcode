//
// Created by Михаил Степанов on 03.08.2020.
//

#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(const string &s) {
        if (s.empty()) { return true; }
        int startPointer = 0;
        int endPointer = s.size() - 1;
        while (startPointer < endPointer) {
            bool skipStep = false;
            if (!isalnum(s[startPointer])) {
                startPointer++;
                skipStep = true;
            }
            if (!isalnum(s[endPointer])) {
                endPointer--;
                skipStep = true;
            }
            if (skipStep) { continue; }
            if (tolower(s[startPointer]) != tolower(s[endPointer])) { return false; }
            startPointer++;
            endPointer--;
        }
        return true;
    }

    bool simpleIsPalindrome(const string &s) {
        // Actually I didn't know that it's possible to use multiple indexes within for loop
        for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
            while (i < j && !isalnum(s[i])) { // Also it's a common pattern: skip as much as possible
                i++;
            }
            while (i < j && !isalnum(s[j])) { // Do not fear to change indexes within the cycle: it's not a python
                j--;
            }
            if (i < j && tolower(s[i]) != tolower(s[j])) { return false; }
        }

        return true;
    }
};


int main() {
    Solution solution;

    cout << solution.isPalindrome("0P") << endl;
    cout << solution.isPalindrome("A man, a plan, a canal: Panama") << endl;
    cout << solution.isPalindrome("race a car") << endl;
    return 0;
}
