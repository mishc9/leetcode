//
// Created by Михаил Степанов on 10.07.2020.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

template<typename T>
struct TreeNode {
    T val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {};

    TreeNode(T x) : val(x), left(nullptr), right(nullptr) {};

    TreeNode(T x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {};
};


template<typename T>
vector<T> bfs(TreeNode<T> *root) {
    if (!root) { return {}; }

    queue<TreeNode<T> *> Q;
    vector<T> result;
    Q.push(root);
    while (!Q.empty()) {
        TreeNode<T> *node = Q.front();
        Q.pop();
        result.emplace_back(node->val);
        if (node->left) { Q.push(node->left); }
        if (node->right) { Q.push(node->right); }
    }
    return result;
}

template<typename T>
vector<T> dfs(TreeNode<T> *root) {
    vector<T> result;
    dfsHelper(root, result);
    return result;
}

template<typename T>
void dfsHelper(TreeNode<T> *node, vector<T> &vec) {
    if (node->left) { dfsHelper(node->left, vec); }
    if (node->right) { dfsHelper(node->right, vec); }
    vec.emplace_back(node->val);
}


template<typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
    for (auto &val: vec) {
        cout << val << " ";
    }
    return os;
}

int main() {
    TreeNode left(2);
    TreeNode right(3);
    TreeNode root(1, &left, &right);

    cout << bfs(&root) << endl;
    cout << dfs(&root) << endl;

    return 0;
}
