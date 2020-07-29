//
// Created by Михаил Степанов on 15.07.2020.
//

#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string res, tmp;
        int i = 0, j, len = s.size();
        while (true) {
            while (i < len && s[i] == ' ') i++;
            if (i >= len) break;
            j = i + 1;
            while (j < len && s[j] != ' ') j++;
            tmp = s.substr(i, j - i);
            if (!res.empty()) {
                res = tmp + " " + res;
            } else {
                res = tmp + "" + res;
            }
            i = j + 1;
        }
        return res;
    }
};

int main() {
    Solution sol;

    cout << sol.reverseWords("the sky is blue") << endl;
    cout << sol.reverseWords("  hello world!  ") << endl;
    cout << sol.reverseWords("a good   example") << endl;
}
