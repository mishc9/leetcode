//
// Created by Михаил Степанов on 13.07.2020.
//


#include <vector>
#include <iostream>

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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (!p and !q) return true;
        if ((q and !p) or (p and !q)) return false;
        if (p->val != q->val) return false;
        return (isSameTree(p->left, q->left) and isSameTree(p->right, q->right));
    }

    bool isSameTreeOneLiner(TreeNode *p, TreeNode *q) {
        // Some people prefers one-liners, but it seems to be slower and harder to read
        return (!p && !q) ||
               p && q && p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
