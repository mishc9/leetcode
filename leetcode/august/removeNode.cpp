//
// Created by Михаил Степанов on 31.08.2020.
//

using namespace std;

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
    TreeNode *minElement(TreeNode *root)
    {
        if (root == nullptr)return nullptr;
        TreeNode *temp = root;
        while (temp->left != nullptr)
            temp = temp->left;
        return temp;
    }

    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == nullptr) { return nullptr; }
        if (key < root->val) { root->left = deleteNode(root->left, key); }
        else if (key > root->val) { root->right = deleteNode(root->right, key); }
        else {
            if (root->left == nullptr) {
                TreeNode *temp = root->right;
                delete root;
                return temp;
            }
            if (root->right == nullptr) {
                TreeNode *temp = root->left;
                delete root;
                return temp;
            }
            TreeNode *leftMost = minElement(root->right);
            root->val = leftMost->val;
            root->right = deleteNode(root->right, leftMost->val);
            return root;
        }
        return root;
    }
};


