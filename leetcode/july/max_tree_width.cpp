//
// Created by Михаил Степанов on 09.07.2020.
//

#include <queue>
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

TreeNode *fromVector(vector<int> vec) {
    TreeNode root;
    for (auto val: vec) {

    }
}

class Solution {
public:
    int widthOfBinaryTree(TreeNode *root) {

        if (root == NULL)
            return 0;

        int result = 0;

        queue<pair<TreeNode *, int>> q;
        q.push(make_pair(root, 1));

        while (!q.empty()) {
            int count = q.size();
            result = max(result, (q.back().second - q.front().second) + 1);
            while (count--) {
                auto[node, val] = q.front();
                q.pop();

                if (node->left) {
                    q.push({node->left, val * 2});
                }

                if (node->right) {
                    q.push({node->left, val * 2 + 1});
                }
            }
        }

        return result;
    }


    int _widthOfBinaryTree(TreeNode *root) {

        if (root == NULL)
            return 0;

        int result = 0;


        queue<pair<TreeNode *, int>> q;
        q.push(make_pair(root, 1));
        while (!q.empty()) {
            // Get the size of queue when the level order
            // traversal for one level finishes
            int count = q.size();
            result = max(result, (q.back().second - q.front().second) + 1);
            while (count--) {
                // Dequeue an node from queue
                auto[node, val] = q.front();
                q.pop();

                if (node->left != NULL) {
                    q.push(make_pair(node->left, 2 * (long) val));
                }

                if (node->right != NULL) {
                    q.push(make_pair(node->right, 2 * (long) val + 1));
                }
            }
        }
        return result;
        // return height;
    }
};

int main() {
    Solution sol;
    TreeNode left{1};
    TreeNode right{3};
    TreeNode levelOneLeft{1, &left, &left};
    TreeNode levelOneRight{3, &right, &right};
    TreeNode treeNode{0, &levelOneLeft, &levelOneRight};
    cout << sol.widthOfBinaryTree(&treeNode) << endl;
    cout << sol.widthOfBinaryTree(&left) << endl;
    cout << sol.widthOfBinaryTree(&right) << endl;
    return 0;
}