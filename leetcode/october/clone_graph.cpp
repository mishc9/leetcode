//
// Created by Михаил Степанов on 20.10.2020.
//

#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Node
{
public:
    int val;
    vector<Node *> neighbors;

    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }

    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }

    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution
{
    unordered_map<Node *, Node *> visited;
public:
    Node *clone(Node *node)
    {
        if (!node) {
            Node *newNode;
            newNode = nullptr;
            return newNode;
        }
        Node *newNode = new Node(node->val);
        visited[node] = newNode;
        newNode->val = node->val;

        vector<Node *> newNeighbours;
        newNeighbours.reserve(node->neighbors.size());

        for (auto subNode: node->neighbors) {
            Node *newSubNode;
            if (visited.count(subNode) == 0) {
                newSubNode = clone(subNode);
            } else {
                newSubNode = visited.at(subNode);
            }
            newNeighbours.emplace_back(newSubNode);
        }
        newNode->neighbors = newNeighbours;
        return newNode;
    }

    Node *cloneGraph(Node *node)
    {
        visited.clear();
        return clone(node);
    }
};