//
// Created by Михаил Степанов on 20.08.2020.
//


struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {};

    ListNode(int value) : val(value), next(nullptr) {};

    ListNode(int value, ListNode *nextNode) : val(value), next(nextNode) {};
};

class Solution {
public:
    void mergeList(ListNode *p, ListNode *q) {
        while (q) {
            ListNode *temp1 = p->next;
            ListNode *temp2 = q->next;
            p->next = q;
            q->next = temp1;
            p = temp1;
            q = temp2;
        }
        ListNode *t;
        // Why is it even worked?  Creat only 1 additional ptr?
//        while (q) {
//            t = p->next;
//            p->next = q;
//            q = q->next;
//            p = p->next;
//            p->next = t;
//            p = p->next;
//        }
    }

    ListNode *reverse(ListNode *head) {
        ListNode *prev = nullptr, *curr = head, *next;  // don't change the head provided by pointer!
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode *findNextToMiddle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *nextToMid = slow->next;
        cutNode(slow);
        return nextToMid;
    }

    void cutNode(ListNode *node) {
        node->next = nullptr;
    }

    void reorderList(ListNode *head) {
        if (!head) { return; }
        ListNode *p = head;
        ListNode *nextToMiddle = findNextToMiddle(head);
        nextToMiddle = reverse(nextToMiddle);
        mergeList(p, nextToMiddle);
    }
};

int main() {
    Solution solution;
    return 0;
}