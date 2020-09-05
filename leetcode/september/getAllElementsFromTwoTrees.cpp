//
// Created by Михаил Степанов on 05.09.2020.
//

#include <vector>
#include <queue>

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
    vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
    {
        vector<int> result;
        queue<int> queue1;
        queue<int> queue2;

        inorder(root1, queue1);
        inorder(root2, queue2);

        while (!queue1.empty() && !queue2.empty()) {
            if (queue1.front() < queue2.front()) {
                result.emplace_back(queue1.front());
                queue1.pop();
            } else {
                result.emplace_back(queue2.front());
                queue2.pop();
            }
        }
        while (!queue1.empty()) {
            result.emplace_back(queue1.front());
            queue1.pop();
        }
        while (!queue2.empty()) {
            result.emplace_back(queue2.front());
            queue2.pop();
        }
        return result;
    }

    void inorder(TreeNode *root, queue<int> &q)
    {
        if (!root) { return; }
        if (root->left) {
            inorder(root->left, q);
        }
        q.push(root->val);
        if (root->right) {
            inorder(root->right, q);
        }
    }
};

