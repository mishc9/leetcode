//
// Created by Михаил Степанов on 17.07.2020.
//

#include <vector>
#include <unordered_map>
#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        vector<int> result;
        unordered_map<int, int> frequency;

        for (int i = 0; i < nums.size(); i++) {
            frequency[nums[i]]++;
        }

        priority_queue<int, vector<int>, greater<>> minHeap;
        for (auto i : frequency) {
            minHeap.push(i.second);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        for (auto i : frequency) {
            if (i.second >= minHeap.top()) {
                result.push_back(i.first);
            }
        }
        return result;
    }
};


template<typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
    for (auto val: vec) {
        cout << val << " ";
    }
    return os;
}


int main() {
    Solution sol;

    vector<int> vec{1, 1, 1, 2, 2, 3};
    cout << sol.topKFrequent(vec, 2) << endl;
    vec = {-1, -1};
    cout << sol.topKFrequent(vec, 1) << endl;

    return 0;
}
