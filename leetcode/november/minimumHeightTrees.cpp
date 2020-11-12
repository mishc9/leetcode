//
// Created by Михаил Степанов on 04.11.2020.
//

#include <vector>
#include <iostream>
#include <tuple>
#include <queue>

using namespace std;

using Edges = vector<vector<int>>;

template<typename T>
ostream &operator<<(ostream &os, const vector<T> &vec)
{
    bool firstStep = true;
    os << "[";
    for (auto &val: vec) {
        if (firstStep) {
            os << val;
            firstStep = false;
        } else {
            os << ", " << val;
        }
    }
    os << "]";
    return os;
}

class Solution
{
public:
    static vector<int> findMinHeightTrees(int n, const vector<vector<int>> &edges)
    {
        vector<int> edgeCount(n, 0);
        vector<int> edgeSum(n, 0);
        int i, n1, n2;
        for (const vector<int> &edge: edges) {
            n1 = edge[0];
            n2 = edge[1];
            edgeCount[n1]++;
            edgeCount[n2]++;
            edgeSum[n1] += n2;
            edgeSum[n2] += n1;
        }
        queue<int> queue;
        for (i = 0; i < n; i++) { if (edgeCount[i] == 1) { queue.push(i); }}

        int root, root1, q_size;

        for (int n0 = n; n0 > 2;) {
            q_size = queue.size();
            for (i = 0; i < q_size; i++) {
                root = queue.front();
                queue.pop();
                root1 = edgeSum[root];
                edgeSum[root1] -= root;
                edgeCount[root1]--;
                if (edgeCount[root1] == 1) { queue.push(root1); }
                edgeCount[root] = -1;
                n0--;
            }
        }
        vector<int> answer;
        for (i = 0; i < n; i++) { if (edgeCount[i] > -1) { answer.push_back(i); }}
        return answer;
    }
};


int main()
{
    Solution solution;

    Edges edges;
    vector<int> answer;

    edges = {{3, 0},
             {3, 1},
             {3, 2},
             {3, 4},
             {5, 4}};
    answer = {3, 4};
    cout << solution.findMinHeightTrees(6, edges) << " " << answer << endl;
    edges = {};
    answer = {0};
    cout << solution.findMinHeightTrees(1, edges) << " " << answer << endl;
    edges = {{0, 1}};
    answer = {0, 1};
    cout << solution.findMinHeightTrees(2, edges) << " " << answer << endl;
    edges = {{1, 0},
             {1, 2},
             {1, 3}};
    answer = {1};
    cout << solution.findMinHeightTrees(4, edges) << " " << answer << endl;

    return 0;
}

