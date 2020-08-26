//
// Created by Михаил Степанов on 14.08.2020.
//

#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    int longestPalindrome(const string &source) {
        unordered_map<int, int> counts;
        int sizeOf = 0;
        bool oddDetected = false;
        for (auto val: source) { counts[val]++; }
        for (auto[key, count]: counts) {
            if ((count % 2) == 0) { sizeOf += count; }
            else {
                oddDetected = true;
                sizeOf += (count / 2) * 2;
            }
        }
        sizeOf += oddDetected;
        return sizeOf;
    }
};


int main() {
    Solution solution;
    cout << solution.longestPalindrome("abccccdd") << endl;
    return 0;
}