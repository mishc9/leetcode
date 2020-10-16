//
// Created by Михаил Степанов on 12.10.2020.
//

#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    static bool buddyStrings(const string &A, const string &B)
    {
        if (A.size() != B.size()) { return false; }
        int firstMismatch = -1;
        int secondMismatch = -1;
        for (int i = 0; i < A.size(); i++) {
            if (A[i] != B[i]) {
                if (firstMismatch == -1) { firstMismatch = i; }
                else if (secondMismatch == -1) { secondMismatch = i; }
                else { return false; }
            }
        }
        if (secondMismatch == -1 and firstMismatch != -1) { return false; }
        else if (firstMismatch == -1) {
            if (A.size() > 26) { return true; }
            else {
                vector<int> values(26);
                for (auto a: A) {
                    values[a - 'a']++;
                }
                return *max_element(values.begin(), values.end()) > 1;
            }
        } else { return A[firstMismatch] == B[secondMismatch] and B[firstMismatch] == A[secondMismatch]; }
    }
};

#include <iostream>

int main()
{
    cout << Solution::buddyStrings("ab", "ba") << " true" << endl;
    cout << Solution::buddyStrings("ab", "ab") << " false" << endl;
    cout << Solution::buddyStrings("aa", "aa") << " true" << endl;
    cout << Solution::buddyStrings("aaaaaaabc", "aaaaaaacb") << " true" << endl;
    cout << Solution::buddyStrings("", "aa") << " false" << endl;
    return 0;
}
