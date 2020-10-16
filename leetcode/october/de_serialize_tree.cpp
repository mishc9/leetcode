//
// Created by Михаил Степанов on 09.10.2020.
//

#include <string>
#include <deque>

using namespace std;

// Definition for a binary tree node.

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec
{

public:

    // Encodes a tree to a single string.

    void serializeHelper(TreeNode *root, string &ans)
    {
        if (!root) {
            return;
        }

        ans += to_string(root->val);
        ans += '$';

        serializeHelper(root->left, ans);
        serializeHelper(root->right, ans);
    }

    string serialize(TreeNode *root)
    {
        string ans;
        serializeHelper(root, ans);
        return ans;
    }

    // Decodes your encoded data to tree.

    TreeNode *deserializeHelper(TreeNode *root, int value)
    {
        if (!root) {
            auto *temp = new TreeNode(value);
            return temp;
        }

        if (value <= root->val) {
            root->left = deserializeHelper(root->left, value);
        } else {
            root->right = deserializeHelper(root->right, value);
        }
        return root;
    }

    TreeNode *deserialize(string data)
    {
        int ptr = 0;
        TreeNode *root = nullptr;
        while (ptr < data.length()) {
            string stringBuffer;

            while (ptr < data.length() and data[ptr] != '$') {
                stringBuffer.append(1, data[ptr]);
                ptr++;
            }
            ptr++;
            root = deserializeHelper(root, stoi(stringBuffer));
        }
        return root;
    }
};
