//
// Created by Михаил Степанов on 05.11.2020.
//

#include <vector>
#include <queue>
#include <iostream>

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
        vector<int> nEdges(n, 0);
        vector<int> edgeSum(n, 0);
        for (const auto &edge: edges) {
            nEdges[edge[0]]++;
            nEdges[edge[1]]++;
            edgeSum[edge[1]] += edge[0];
            edgeSum[edge[0]] += edge[1];
        }

        queue<int> queue;
        for (int i = 0; i < n; i++) { if (nEdges[i] == 1) { queue.push(i); }}

        for (int nodeCount = n; nodeCount > 2;) {
            int qSize = queue.size();
            for (int i = 0; i < qSize; i++) {
                int leaf = queue.front();
                queue.pop();
                int tmp = edgeSum[leaf];
                edgeSum[tmp] -= leaf;
                nEdges[tmp]--;
                if (nEdges[tmp] == 1) { queue.push(tmp); }
                nEdges[leaf] = -1;
                nodeCount--;
            }
        }
        vector<int> answer;
        for (int i = 0; i < n; i++) { if (nEdges[i] > -1) { answer.push_back(i); }}
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
