//
// Created by Михаил Степанов on 08.08.2020.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {};

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};

    TreeNode(int x, TreeNode *lNode, TreeNode *rNode) : val(x), left(lNode), right(rNode) {};
};


class Solution {
public:
    int result = 0, sum;
    unordered_map<int, int> cache;

    void dfs(TreeNode *root, int partialSum = 0) {
        partialSum += root->val;
        result += cache[partialSum - sum];
        cache[partialSum]++;
        if (root->left) dfs(root->left, partialSum);
        if (root->right) dfs(root->right, partialSum);
        cache[partialSum]--;
    }

    int pathSum(TreeNode *root, int targetSum) {
        sum = targetSum;
        cache[0] = 1;
        if (!root) return result;
        dfs(root);
        return result;
    }

    int _pathSum(TreeNode *root, int sum) {
        int result = 0;
        for (const auto &path: getAllPaths(root)) {
            result += arraySum(path, sum);
        }
        return result;

    }

    vector<vector<int>> getAllPaths(TreeNode *root) {

    }

    int pathSumHelper(TreeNode *root, int sum, unordered_map<int, int> &previousSums) {
        int result = 0;
        if (!root->val) { return result; }
        if (root->left) { result += pathSum(root->left, sum); }
        if (root->right) { result += pathSum(root->right, sum); }
        return result;
    }

    int arraySum(const vector<int> &array, int targetSum) {
        int result = 0;
        int currSum = 0;
        unordered_map<int, int> previousSum;
        for (int i : array) {
            currSum += i;
            if (currSum == targetSum) { result++; }
            if (previousSum.count(currSum - targetSum) > 0) {
                result += previousSum.at(currSum - targetSum);
            }
            previousSum[currSum]++;
        }
        return result;
    }
};


int main() {
    Solution solution;
    cout << solution.arraySum({1, -1, 1, -1}, 0) << endl;
    cout << solution.arraySum({0, 0, 0, 0}, 0) << endl;
    cout << solution.arraySum({10, 2, -2, -20, 10}, -10) << endl;
    return 0;
}
