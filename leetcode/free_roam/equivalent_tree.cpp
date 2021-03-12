//
// Created by Михаил Степанов on 05.02.2021.
//

#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct Tree
{
    int val;
    Tree *left;
    Tree *right;

    Tree(int val) : val(val) {};

    Tree(int val, Tree *left, Tree *right) : val(val), left(left), right(right) {};
};

void tree_inorder(vector<int> &lvec, stack<int> &s);

void inord(Tree *tree, stack<int> &stack)
{
    if (!tree) { return; }
    inord(tree->left, stack);
    stack.push(tree->val);
    inord(tree->right, stack);
}

bool eq_trees(Tree *ltree, Tree *rtree)
{
    vector<int> lvec;
    vector<int> rvec;

    stack<int> s;

    inord(ltree, s);

    tree_inorder(lvec, s);

    inord(rtree, s);
    tree_inorder(rvec, s);

    if (lvec.size() != rvec.size()) { return false; }

    for (int i = 0; i < lvec.size(); i++) {
        if (lvec[i] != rvec[i]) { return false; }
    }

    return true;
}

void tree_inorder(vector<int> &lvec, stack<int> &s)
{
    while (!s.empty()) {
        auto val = s.top();
        s.pop();
        lvec.emplace_back(val);
    }
}
