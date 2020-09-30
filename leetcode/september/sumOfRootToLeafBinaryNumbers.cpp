//
// Created by Михаил Степанов on 08.09.2020.
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
public:
    int sumRootToLeaf(TreeNode *root)
    {
        sum = 0;
        preorder(root, 0);
        return sum;
    }

    static bool isLeaf(TreeNode *root)
    {
        return !(root->left || root->right);
    }

    void preorder(TreeNode *root, int acc)
    {
        if (!root) { return; }
        acc = acc * 2 + root->val;
        if (isLeaf(root)) {
            sum += acc;
            return;
        }
        if (root->left) { preorder(root->left, acc); }
        if (root->right) { preorder(root->right, acc); }
    }

private:
    int sum;
};