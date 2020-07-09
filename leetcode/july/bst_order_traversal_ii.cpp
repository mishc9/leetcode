//
// Created by Михаил Степанов on 02.07.2020.
//

#include <vector>
#include <iostream>
#include <queue>
#include <stack>


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
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        if (!root) {
            vector<vector<int>> empty;
            return empty;
        }
        vector<vector<int>> result;
        queue<TreeNode *> queue;
        stack<vector<int>> stack;

        queue.push(root);
        while (!queue.empty()) {
            int size = queue.size();
            vector<int> level;
            while (size-- > 0) {
                root = queue.front();
                queue.pop();
                level.emplace_back(root->val);
                if (root->left) {
                    queue.push(root->left);
                }
                if (root->right) {
                    queue.push(root->right);
                }
            }
            stack.push(level);
        }

        while (!stack.empty()) {

            result.emplace_back(stack.top());
            stack.pop();

        }
        return result;
    }
};

int main() {
    TreeNode ln = TreeNode(9);
    auto a = TreeNode(15);
    auto b = TreeNode(7);
    TreeNode rn = TreeNode(20, &a, &b);
    TreeNode node = TreeNode(
            3,
            &ln,
            &rn
    );
    auto sol = Solution();
    sol.levelOrderBottom(&node);

    return 0;
}
