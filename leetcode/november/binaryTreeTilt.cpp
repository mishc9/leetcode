//
// Created by Михаил Степанов on 09.11.2020.
//

#include <cstdlib>

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution
{
    int totalTilt = 0;

    int valueSum(TreeNode *node)
    {
        if (!node) { return 0; }

        int leftSum = valueSum(node->left);
        int rightSum = valueSum(node->right);
        int tilt = std::abs(leftSum - rightSum);
        totalTilt += tilt;

        return node->val + leftSum + rightSum;
    }

public:

    int findTilt(TreeNode *root)
    {
        totalTilt = 0;
        valueSum(root);
        return totalTilt;
    }
};