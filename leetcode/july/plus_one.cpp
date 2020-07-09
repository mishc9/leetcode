//
// Created by Михаил Степанов on 06.07.2020.
//

#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

template<typename T>
ostream &operator<<(ostream &os, vector<T> vec) {
    for (auto val:vec) { os << val; }
    return os;
}

template<typename T>
istream &operator>>(istream &is, vector<T> &vec) {
    T val;
    while (is.tellg() != -1) {
        is >> val;
        vec.emplace_back(val);
    }
    return is;
}

class Solution {
public:
    /*
     * It looks much simpler, but for some strange reason it's also much slower and requires more memory
     * The reason is clear now. It's because of &reference
     */
    vector<int> plusOne(vector<int> &digits) {
        int n = digits.size() - 1;

        for (int i = n; i >= 0; --i) {
            if (digits[i] == 9) {
                digits[i] = 0;
            } else {  // current digit is not 9 so we can safely increment by one
                digits[i] += 1;
                return digits;
            }
        }
        digits.push_back(0);
        digits[0] = 1;
        return digits;
    }

    /*
     * Below is my own solution, the same logic, but not optimized
     */
    vector<int> _plusOne(vector<int> &digits) {
        bool bitShift = false;
        int n_steps = digits.size();
        while (n_steps--) {
            if (digits[n_steps] == 9) {
                if (!bitShift) {
                    digits.emplace_back(0);
                    bitShift = true;
                } else {
                    digits[n_steps + 1] = 0;
                }
            } else {
                digits[n_steps] += 1;
                break;
            }
        }
        if (!bitShift) {
            return digits;
        }
        if (n_steps < 0) {
            digits[n_steps + 1] = 1;
        } else {
            digits[n_steps + 1] = digits[digits.size() - 1];
            digits.pop_back();
        }
        return digits;
    }

};

};


int main() {
    Solution sol;
    vector<string> vecs{
            "4 3 2 1",
            "4 3 2 9",
            "4 3 2 9 9",
            "9 9",
            "1 9 9",
            "0"
    };
    for (auto &vec : vecs) {
        istringstream ss(vec);
        vector<int> vec_form;
        ss >> vec_form;
        cout << vec_form << " plus one equals " << sol.plusOne(vec_form) << endl;
    }
    return 0;
}
