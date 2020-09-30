//
// Created by Михаил Степанов on 27.09.2020.
//

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

using Equation = vector<vector<string>>;
using Graph = unordered_map<string, unordered_map<string, double>>;


class Solution
{
public:
    vector<double> calcEquation(Equation &equations,
                                vector<double> values,
                                Equation &queries)
    {
        Graph graph;

        // Step 1). build the graph from the equations
        for (int i = 0; i < equations.size(); i++) {
            vector<string> equation = equations[i];
            string dividend = equation[0], divisor = equation[1];
            double quotient = values[i];

            if (graph.count(dividend) == 0) {
                unordered_map<string, double> tmp;
                graph[dividend] = tmp;
            }
            if (graph.count(divisor) == 0) {
                unordered_map<string, double> tmp;
                graph[divisor] = tmp;
            }
            graph[dividend][divisor] = quotient;
            graph[divisor][dividend] = 1 / quotient;
        }

        // Step 2). Evaluate each query via backtracking (DFS)
        // by verifying if there exists a path from dividend to divisor
        vector<double> results(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            vector<string> query = queries[i];
            string dividend = query[0], divisor = query[1];

            if (graph.count(dividend) == 0 || graph.count(divisor) == 0) { results[i] = -1.0; }
            else if (dividend == divisor) { results[i] = 1.0; }
            else {
                unordered_set<string> visited;
                results[i] = backtrackEvaluate(graph, dividend, divisor, 1, visited);
            }
        }

        return results;
    }

private:
    double backtrackEvaluate(Graph &graph,
                             string &currNode,
                             string &targetNode,
                             double accProduct,
                             unordered_set<string> &visited)
    {
        // mark the visit
        visited.insert(currNode);
        double ret = -1.0;

        unordered_map<string, double> neighbors = graph[currNode];
        if (neighbors.count(targetNode) != 0) { ret = accProduct * neighbors.at(targetNode); }
        else {
            for (auto &pair : neighbors) {
                string nextNode = pair.first;
                if (visited.count(nextNode) != 0) { continue; }
                ret = backtrackEvaluate(graph,
                                        nextNode,
                                        targetNode,
                                        accProduct * pair.second,
                                        visited);
                if (ret != -1.0) { break; }
            }
        }
        // unmark the visit, for the next backtracking
        visited.erase(currNode);
        return ret;
    }
};

template<typename T>
ostream &operator<<(ostream &os, const vector<T> &vec)
{
    os << "[";
    bool firstStep = true;

    for (const auto &val: vec) {
        if (firstStep) {
            os << val;
            firstStep = false;
            continue;
        }
        os << ", " << val;
    }
    os << "];";
    return os;
}

int main()
{
    Solution solution;
    Equation equation{{"a", "b"},
                      {"b", "c"}};
    vector<double> values{2.0, 3.0};
    Equation queries{{"a", "c"},
                     {"b", "a"},
                     {"a", "e"},
                     {"a", "a"},
                     {"x", "x"}};
    cout << solution.calcEquation(equation, values, queries) << endl;
    return 0;
}
