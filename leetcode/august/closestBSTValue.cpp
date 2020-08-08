//
// Created by Михаил Степанов on 08.08.2020.
//

#include <iostream>
#include <cmath>

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
    int closestValue(TreeNode *node, double target) {
        int candidate = node->val;
        while (true) {
            // if (node->val == target) { return candidate; }
            if (target < node->val) {
                if (!node->left) { return candidate; }
                else {
                    node = node->left;
                    if (abs(node->val - target) < abs(candidate - target)) {
                        candidate = node->val;
                    }
                }
            } else {
                if (!node->right) { return candidate; }
                else {
                    node = node->right;
                    if (abs(node->val - target) < abs(candidate - target)) {
                        candidate = node->val;
                    }
                }
            }
        }
    }
};


int main() {
    Solution solution;
    return 0;
}
