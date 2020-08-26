//
// Created by Михаил Степанов on 11.08.2020.
//

#include <vector>
#include <iostream>


using namespace std;

class Solution {
public:
    int hIndex(vector<int> &citations) {
        sort(citations.begin(), citations.end());
        int h = 0, hCandidate;
        for (int i = 0; i < citations.size(); i++) {
            hCandidate = citations.size() - i;
            if (hCandidate <= citations[i]) { h = max(h, hCandidate); }
        }
        return h;
    }

    int hIndexCountSort(const vector<int> &citations) {
        int n = citations.size();
        vector<int> papers(n + 1, 0);
        // counting papers for each citation number
        for (int c: citations) { papers[min(n, c)]++; }
        // finding the h-index
        int k = n;
        for (int s = papers[n]; k > s; s += papers[k]) { k--; }
        return k;
    }
};


int main() {
    Solution solution;
    vector<int> citations{3, 0, 6, 1, 5};
    cout << solution.hIndex(citations) << endl;
    return 0;
}