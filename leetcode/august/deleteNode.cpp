//
// Created by Михаил Степанов on 31.08.2020.
//

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {};

    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {};

    TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right) {};
};


class Solution
{
public:
    TreeNode *deleteNode(TreeNode *root, int val)
    {
        TreeNode *toRemove = findNode(root, val);
        if (!toRemove) { return root; }
        if (toRemove->right) {
            toRemove->val = toRemove->right->val;
            TreeNode *leftBuf = toRemove->right->left;
            toRemove->right = toRemove->right->right;
            if (toRemove->left) {
                TreeNode *leftCut = toRemove->left;
                toRemove->left = leftBuf;
                leftMost(toRemove)->left = leftCut;
            } else { toRemove->left = leftBuf; }
        } else {
            if (toRemove->left) {
                toRemove->val = toRemove->left->val;
                toRemove->left = toRemove->left->left;
                toRemove->right = toRemove->left->right;
            } else { toRemove = toRemove->left; }
        }
        return root;
    };

    TreeNode *findNode(TreeNode *root, int val)
    {
        if (!root) { return root; }
        if (root->val == val) { return root; }
        if (root->val < val) { return findNode(root->right, val); }
        if (root->val > val) { return findNode(root->left, val); }
        return nullptr;
    }

    TreeNode *leftMost(TreeNode *root)
    {
        if (!root) { return root; }
        if (!root->left) { return root; }
        return leftMost(root->left);
    }
};
