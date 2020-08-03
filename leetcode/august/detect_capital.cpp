//
// Created by Михаил Степанов on 01.08.2020.
//

#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool detectCapitalUse(const string &word) {
        if (word.empty() or word.size() == 1) { return true; }
        if (isupper(word[0])) {
            bool isUpper = isupper(word[1]);
            for (int i = 2; i < word.size(); i++) {
                if ((isUpper && !isupper(word[i]))
                    || (!isUpper && isupper(word[i]))) { return false; }
            }
        } else { for (int i = 1; i < word.size(); i++) { if (isupper(word[i])) { return false; }}}
        return true;
    }
};


int main() {
    Solution sol;
    cout << sol.detectCapitalUse("USA") << endl;
    cout << sol.detectCapitalUse("leetcode") << endl;
    cout << sol.detectCapitalUse("Google") << endl;
    cout << sol.detectCapitalUse("SWaG") << endl;
    cout << sol.detectCapitalUse("swaG") << endl;
    cout << sol.detectCapitalUse("SWAg") << endl;
    return 0;
};
