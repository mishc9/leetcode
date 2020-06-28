//
// Created by Михаил Степанов on 27.06.2020.
//


#include <tcl.h>

/*
 */

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
    TreeNode *invertTree(TreeNode *root) {
        if (!root) {
            return root;
        }

        TreeNode *buff;
        buff = root->left;
        root->left = root->right;
        root->right = buff;

        if (root->left) {
            root->left = invertTree(root->left);
        }
        if (root->right) {
            root->right = invertTree(root->right);
        }
        return root;
    }
};
