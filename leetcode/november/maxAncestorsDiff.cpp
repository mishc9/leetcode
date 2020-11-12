//
// Created by Михаил Степанов on 09.11.2020.
//


#include <vector>

using namespace std;

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
    int minAncHelper(TreeNode *root, int minVal, int maxVal)
    {
        if (!root) { return maxVal - minVal; }

        maxVal = max(root->val, maxVal);
        minVal = min(root->val, minVal);

        int leftMax = minAncHelper(root->left, minVal, maxVal);
        int rightMax = minAncHelper(root->right, minVal, maxVal);

        return max(leftMax, rightMax);
    }

public:
    int maxAncestorDiff(TreeNode *root)
    {
        if (!root) { return 0; }
        return minAncHelper(root, root->val, root->val);
    }
};

