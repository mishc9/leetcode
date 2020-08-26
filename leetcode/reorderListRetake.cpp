//
// Created by Михаил Степанов on 21.08.2020.
//

struct ListNode
{
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {};

    ListNode(int x) : val(x), next(nullptr) {};

    ListNode(int x, ListNode *node) : val(x), next(node) {};
};

class Solution
{
public:
    void reorderList(ListNode *head)
    {
        if (!head) { return; }
        ListNode *middle = nextToMiddle(head);
        ListNode *reversed = reverse(middle);
        mergeCloseSized(head, reversed);
    }

    ListNode *nextToMiddle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *nextMiddle = slow->next;
        slow->next = nullptr;
        return nextMiddle;
    }

    ListNode *reverse(ListNode *head)
    {
        ListNode *curr = head;
        ListNode *prev = nullptr;
        ListNode *next;
        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    void mergeCloseSized(ListNode *fst, ListNode *snd)
    {
        while (snd)
        {
            ListNode *tmp1 = fst->next;
            ListNode *tmp2 = snd->next;
            fst->next = snd;
            snd->next = tmp1;
            fst = tmp1;
            snd = tmp2;
        }
    }
};


