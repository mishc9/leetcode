//
// Created by Михаил Степанов on 23.10.2020.
//


#include <algorithm>
#include <climits>

using namespace std;

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
    static void helper(TreeNode *root, int count, int &finalCount)
    {
        if (root == nullptr) {
            finalCount = min(finalCount, count);
            return;
        }

        if (root->left == nullptr and root->right == nullptr) {
            finalCount = min(finalCount, count + 1);
            return;
        }

        if (root->left) { helper(root->left, count + 1, finalCount); }

        if (root->right) { helper(root->right, count + 1, finalCount); }
    }

    static int minDepth(TreeNode *root)
    {
        int finalCount = INT_MAX;
        helper(root, 0, finalCount);
        return finalCount;
    }
};
