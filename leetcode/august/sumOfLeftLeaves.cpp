//
// Created by Михаил Степанов on 24.08.2020.
//


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
private:
    int acc;
public:
    int sumOfLeftLeaves(TreeNode *root)
    {
        acc = 0;
        if (root) { postOrder(root); }
        return acc;
    }

    void postOrder(TreeNode *root, bool leftChild = false)
    {
        if (root->left) { postOrder(root->left, true); }
        if (root->right) { postOrder(root->right); }
        if (leftChild && !root->left && !root->right) { acc += root->val; }
    }
};
