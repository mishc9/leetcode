//
// Created by Михаил Степанов on 07.08.2020.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>


using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

using BFS = queue<pair<TreeNode *, pair<int, int>>>;
using Table = vector<vector<int>>;

class Solution {
public:
    struct comp {
        bool operator()(const pair<int, int> &x, const pair<int, int> &y) {
            if (x.first == y.first)
                return x.second > y.second;
            return x.first < y.first;
        }
    };

    Table verticalTraversal(TreeNode *root) {
        BFS bfs;
        Table result;
        map<int, priority_queue<pair<int, int>, vector<pair<int, int>>, comp>> hash;

        if (!root) { return {}; }
        bfs.push({root, {0, 0}});
        while (!bfs.empty()) {
            auto[node, coord] = bfs.front();
            auto[x, y] = coord;
            bfs.pop();
            hash[x].push({y, node->val});
            if (node->left) { bfs.push({node->left, {x - 1, y - 1}}); }
            if (node->right) { bfs.push({node->right, {x + 1, y - 1}}); }
        }

        vector<int> temp;

        for (const auto &item: hash) {
            auto[x, pQueue] = item;
            while (!pQueue.empty()) {
                temp.emplace_back(pQueue.top().second);
                pQueue.pop();
            }
            result.emplace_back(temp);
            temp.clear();
        }
        return result;
    }
};

template<typename T>
ostream &operator<<(ostream &os, const vector<T> vec) {
    cout << "[";
    for (auto &val :vec) { os << val << ", "; }
    cout << "]";
    return os;
}

int main() {
    Solution solution;

    return 0;
}

