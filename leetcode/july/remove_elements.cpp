//
// Created by Михаил Степанов on 20.07.2020.
//

#include <iostream>
#include <sstream>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode *removeElements(ListNode *head, int val) {
        while (head && head->val == val) { head = head->next; }
        if (!head) { return nullptr; }
        ListNode *curr = head->next, *prev = head;
        while (curr) {
            if (curr->val == val) {
                prev->next = curr->next;
                curr = curr->next;
                continue;
            }
            curr = curr->next;
            prev = prev->next;
        }
        return head;
    }
};


ostream &operator<<(ostream &os, const ListNode *node) {
    while (node->next) {
        os << node->val << ", ";
        node = node->next;
    }
    return os;
}

istream &operator>>(istream &is, ListNode *node) {
    int p;
    bool firstStep = true;
    while (true) {
        if (is.tellg() != -1) {
            if (!firstStep) {
                ListNode *next;
                node->next = next;
            }
            is >> p;
            node->val = p;
            firstStep = false;
        } else {
            break;
        }
    }
    return is;
}

int main() {
    Solution sol;
    ListNode node;
    istringstream is("1 2 3");
    return 0;
}

