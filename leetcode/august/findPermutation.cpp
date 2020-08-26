//
// Created by Михаил Степанов on 15.08.2020.
//

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findPermutation(string &s) {
        vector<int> res(s.length() + 1, 0);
        res[0] = 1;
        int i = 1;
        while (i <= s.length()) {
            res[i] = i + 1;
            int j = i;
            if (s[i - 1] == 'D') {
                while (i <= s.length() && s[i - 1] == 'D') { i++; }
                for (int k = j - 1, c = i; k <= i - 1; k++, c--) { res[k] = c; }
            } else { i++; }
        }
        return res;
    }
};