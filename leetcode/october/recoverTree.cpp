//
// Created by Михаил Степанов on 31.10.2020.
//

//Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


#include <stack>

using namespace std;

class Solution
{
public:
    void recoverTree(TreeNode *root)
    {
        stack<TreeNode *> pointers;
        int prev;
        TreeNode *prevNode = nullptr, *node_one = nullptr, *node_2 = nullptr;
        bool flag = true, flag2 = true;
        while (!pointers.empty() || root != nullptr) {
            if (root != nullptr) {
                pointers.push(root);
                root = root->left;
            } else {
                root = pointers.top();
                if (flag) {
                    prev = root->val;
                    prevNode = root;
                    flag = false;
                } else {
                    if (flag2) {
                        if (root->val < prev) {
                            flag2 = false;
                            node_one = prevNode;
                            node_2 = root;
                        }
                        prev = root->val;
                        prevNode = root;
                    } else {
                        if (root->val > node_one->val) {
                            prevNode->val = node_one->val;
                            node_one->val = prev;
                            return;
                        }
                        node_2 = root;
                        prev = root->val;
                        prevNode = root;
                    }
                }
                pointers.pop();
                root = root->right;
            }
        }
        prev = node_one->val;
        node_one->val = node_2->val;
        node_2->val = prev;
    }
};


