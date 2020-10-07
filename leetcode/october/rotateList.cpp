//
// Created by Михаил Степанов on 07.10.2020.
//


//Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct Tail
{
    ListNode *tail;
    int length;
};

class Solution
{
public:
    static Tail listLength(ListNode *head)
    {
        int size = 0;
        ListNode *prev = nullptr;
        while (head) {
            prev = head;
            head = head->next;
            size++;
        }
        return {prev, size};
    }

    static ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head) { return head; }

        auto[tail, listSize] = listLength(head);
        int rotateBy = listSize - (k % listSize);

        if (rotateBy == 0 || rotateBy == listSize) { return head; }
        else {
            ListNode *start = head;
            for (int i = 0; i < rotateBy - 1; i++) {
                head = head->next;
            }
            ListNode *newHead = head->next;
            head->next = nullptr;
            tail->next = start;
            return newHead;
        }
    }
};

#include <iostream>

int main()
{
    auto *node = new ListNode;
    std::cout << Solution::listLength(node).length << std::endl;
    node->next = new ListNode(1);
    std::cout << Solution::listLength(node).length << std::endl;
    return 0;
}

