//
// Created by Михаил Степанов on 10.07.2020.
//


#include <utility>

using namespace std;

// Definition for a Node.


class Node {
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};

class Solution {
public:
    Node *flatten(Node *head) {
        // my solution
        auto[headCopy, tail] = unrollHelper(head);
        return head;
    }

    pair<Node *, Node *> unrollHelper(Node *head) {
        if (!head) {
            return {head, head};
        }
        Node *node = head;
        Node *tail = head;
        while (true) {
            if (node->child) {
                Node *child = node->child;
                node->child = nullptr;
                Node *next = node->next;
                auto[nodeCopy, tail] = unrollHelper(child);
                child->prev = node;
                tail->next = next;
                if (next) { next->prev = tail; }
                node->next = child;
                node = tail;
            }
            if (node->next) { node = node->next; }
            else { return {head, node}; }
        }
    }

    Node *_flatten(Node *head) {
        // seems to be slower, but there's no helpers
        if (!head) return NULL;
        Node *trav = head;
        while (trav) {
            if (trav->child) {
                Node *next = trav->next;
                Node *child = flatten(trav->child);
                trav->child = NULL;
                trav->next = child;
                child->prev = trav;
                Node *lastNode = child;
                while (lastNode->next) lastNode = lastNode->next;
                lastNode->next = next;
                if (next) next->prev = lastNode;
            }
            trav = trav->next;
        }
        return head;
    }


    Node *flattenFast(Node *head) {
        // kinda more effective (may be?)
        if (head == NULL)
            return head;

        Node *flat_head = head;
        Node *flat_itr = head;
        int count = 0;
        while (flat_itr != NULL) {
            Node *next_itr = flat_itr->next;
            if (flat_itr->child != NULL) {
                Node *flatten_child = flatten(flat_itr->child);

                flat_itr->child = NULL;
                flat_itr->next = flatten_child;
                flatten_child->prev = flat_itr;

                Node *child_end = flatten_child;
                while (child_end->next != NULL)
                    child_end = child_end->next;

                if (next_itr != NULL)
                    next_itr->prev = child_end;
                child_end->next = next_itr;
            }
            flat_itr = next_itr;
        }
        return flat_head;
    }
};
