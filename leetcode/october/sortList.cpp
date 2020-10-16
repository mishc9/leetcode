//
// Created by Михаил Степанов on 13.10.2020.
//

using namespace std;

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
    ListNode *_head;

public:
    Solution() : _head(nullptr) {}

    Solution(ListNode *head) : _head(head) {}

    ListNode *sortList(ListNode *head)
    {
        _head = head;
        ListNode *tail = getTail(head);
        quicksort(_head, tail);
        return _head;
    }

    void quicksort(ListNode *head, ListNode *tail)
    {
        if (head == tail) { return; }
        ListNode *pivot = getPivot(head, tail);
        partition(head, tail, pivot);
        quicksort(head, pivot);
        quicksort(pivot, tail);
    }

    ListNode *partition(ListNode *head, ListNode *tail, ListNode *pivot)
    {

    }

    ListNode *getPivot(ListNode *head, ListNode *tail)
    {

    }

    ListNode *head() { return _head; }

    void swap(ListNode *preA, ListNode *preB)
    {
        ListNode *B, *A;
        ListNode *bNext = nullptr, *aNext = nullptr;
        if (preB) { B = preB->next; }
        else { B = _head; }
        if (preA) { A = preA->next; }
        else { A = _head; }
        if (B->next) { bNext = B->next; }
        if (A->next) { aNext = A->next; }

        if (preA) {
            preA->next = B;
            B->next = aNext;
        } else {
            _head = B;
            B->next = aNext;
        }
        if (preB) {
            preB->next = A;
            A->next = bNext;
        } else {
            _head = A;
            A->next = bNext;
        }
    }

    ListNode *getTail(ListNode *head)
    {
        if (!head) { return nullptr; }
        ListNode *prevVal = head;
        while (prevVal->next) { prevVal = prevVal->next; }
        return prevVal;
    }
};

#include <iostream>

int main()
{
    auto *three = new ListNode(3);
    auto *two = new ListNode(2, three);
    auto *one = new ListNode(1, two);
    Solution solution(one);

    cout << "original order (1, 2, 3)" << endl;

    cout << "swap head and tailNode" << endl;
    cout << "head " << solution.head()->val << endl;
    solution.swap(nullptr, two);
    cout << "head " << solution.head()->val << endl;

    cout << "swap head and tailNode again (restore (1, 2, 3))" << endl;
    cout << "head " << solution.head()->val << endl;
    solution.swap(nullptr, two);
    cout << "head " << solution.head()->val << endl;

    cout << "swap head and head" << endl;
    solution.swap(nullptr, nullptr);

    cout << solution.head()->val << endl;
    cout << solution.head()->next->val << endl;
    cout << solution.head()->next->next->val << endl;

    cout << "swap middle and middle" << endl;
    solution.swap(one, one);

    cout << solution.head()->val << endl;
    cout << solution.head()->next->val << endl;
    cout << solution.head()->next->next->val << endl;

    return 0;
}
