//
// Created by Михаил Степанов on 14.11.2020.
//

#include_next <queue>

using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
            : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    static Node *connect(Node *root)
    {
        if (!root) { return root; }
        queue<Node *> queue;
        queue.push(root);
        while (!queue.empty()) {
            int n = queue.size();
            for (int i = 0; i < n; i++) {
                Node *node = queue.front();
                queue.pop();
                if (i != n - 1) { node->next = queue.front(); }
                if (node->left) { queue.push(node->left); }
                if (node->right) { queue.push(node->right); }
            }
        }
        return root;
    }
};

