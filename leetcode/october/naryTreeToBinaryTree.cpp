//
// Created by Михаил Степанов on 31.10.2020.
//

#include <vector>

using namespace std;

class Node
{
public:
    int val;

    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }


    Node(int _val, vector<Node *> &_children)
    {
        val = _val;
        children = _children;
    }
};


class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) { val = x; }
};

class Codec
{

public:

    TreeNode *encode(Node *root)
    {
        if (!root) { return nullptr; }

        TreeNode *newRoot = new TreeNode(root->val);

        if (root->children.size() > 0) {
            Node *firstChild = root->children[0];
            newRoot->left = encode(firstChild);
        }

        TreeNode *sibling = newRoot->left;
        for (int i = 1; i < root->children.size(); ++i) {
            sibling->right = encode(root->children[i]);
            sibling = sibling->right;
        }

        return newRoot;
    }

    Node *decode(TreeNode *root)
    {
        if (!root) {
            return nullptr;
        }

        vector<Node *> newVec;
        Node *newRoot = new Node(root->val, newVec);

        TreeNode *sibling = root->left;
        while (sibling) {
            newRoot->children.emplace_back(decode(sibling));
            sibling = sibling->right;
        }

        return newRoot;
    }
};
