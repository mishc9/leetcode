//
// Created by Михаил Степанов on 07.03.2020.
//

#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

ostream &operator<<(ostream &stream, const unordered_map<int, int> &m) {
    bool first = true;
    for (const auto &[a, b] : m) {
        if (first) {
            cout << '{' << a << ':' << b;
            first = false;
        } else {
            cout << ", " << a << ':' << b;
        }
    }
    cout << '}';
    return stream;
}


int LongestSubseq(vector<int> sequence) {
    int l = 0;
    int sum = 0;
    unordered_map<int, int> longest_seq;

    for (int i = 0; i < sequence.size(); ++i) {
        sum += sequence[i];

        if ((sum == 0) && (l == 0)) {
            l = 1;
        }
        if (sum == 0) {
            l = i + 1;
        }

        if (longest_seq.count(sum) != 0) {
            l = max(l, i - longest_seq[sum]);
        } else {
            longest_seq[sum] = i;
        }
        cerr << longest_seq << endl;
    }
    return l;
}


int main() {
    cout << LongestSubseq({0, 0, 0, 0}) << endl;
    cout << LongestSubseq({4, -2, 2, -3}) << endl;
    cout << LongestSubseq({4, -2, 2, -4}) << endl;
    cout << LongestSubseq({4, -2, 2, -4, 2, -5, 5, -2}) << endl;
    return 0;
}
