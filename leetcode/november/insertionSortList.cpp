//
// Created by Михаил Степанов on 02.11.2020.
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

class Solution
{
public:
    ListNode *insertionSortList(ListNode *head)
    {
        if (!head) { return head; }

        ListNode *prev = head;
        ListNode *nextValue;

        for (ListNode *ptr = head->next; ptr != nullptr; ptr = nextValue) {
            nextValue = ptr->next;
            if (prev->val <= ptr->val) { prev = ptr; }
            else {
                ListNode *pseudoHead = head;
                prev->next = nextValue;

                if (pseudoHead->val > ptr->val) {
                    ptr->next = head;
                    head = ptr;
                } else {
                    while (pseudoHead != prev) {
                        if ((pseudoHead->next)->val > ptr->val) {
                            auto temporary = pseudoHead->next;
                            pseudoHead->next = ptr;
                            ptr->next = temporary;
                            break;
                        }
                        pseudoHead = pseudoHead->next;
                    }
                }
            }
        }
        return head;
    }
};

