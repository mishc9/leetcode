//
// Created by Михаил Степанов on 27.10.2020.
//


//Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (!head) { return head; }
        ListNode *slowPtr = head;
        ListNode *fastPtr = head;

        do {
            if (slowPtr->next) { slowPtr = slowPtr->next; }
            else { return nullptr; }
            if (fastPtr->next && fastPtr->next->next) { fastPtr = fastPtr->next->next; }
            else { return nullptr; }
        } while (slowPtr != fastPtr);
        // Slow ptr is intersection here
        while (head != slowPtr) {
            head = head->next;
            slowPtr = slowPtr->next;
        }
        return head;
    }
};

