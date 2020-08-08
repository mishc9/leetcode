//
// Created by Михаил Степанов on 05.08.2020.
//

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;


class Solution {
public:
    bool isPalindrome(const string &str) {
        for (int i = 0, j = str.size() - 1; i < j; i++, j--) {
            while (i < j && !isalnum(str[i])) { i++; }
            while (i < j && !isalnum(str[j])) { j--; }
            if (i < j && tolower(str[i]) != tolower(str[j])) { return false; }
        }
        return true;
    }
};

int main() {
    Solution solution;
    cout << solution.isPalindrome("A man, a plan, a canal: Panama") << endl;
    cout << solution.isPalindrome("race a car") << endl;
    return 0;
}