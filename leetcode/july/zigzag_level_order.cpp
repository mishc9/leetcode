//
// Created by Михаил Степанов on 22.07.2020.
//

#include <vector>
#include <queue>
#include <stack>

using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        if (!root) { return {}; }
        vector<vector<int>> result;
        bool leftToRight = true;

        stack<TreeNode *> S;
        S.push(root);

        while (!S.empty()) {
            vector<int> level;
            vector<TreeNode *> helper;
            int size = S.size();
            for (int i = 0; i < size; i++) {
                TreeNode *node = S.top();
                S.pop();
                level.emplace_back(node->val);
                if (leftToRight) {
                    if (node->left) { helper.emplace_back(node->left); }
                    if (node->right) { helper.emplace_back(node->right); }
                } else {
                    if (node->right) { helper.emplace_back(node->right); }
                    if (node->left) { helper.emplace_back(node->left); }
                }
            }
            for (auto val : helper) {
                S.push(val);
            }
            leftToRight = !leftToRight;
            result.emplace_back(level);
        }
        return result;
    }
};

