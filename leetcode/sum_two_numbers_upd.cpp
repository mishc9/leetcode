//
// Created by Михаил Степанов on 22.03.2020.
//

#include <iostream>

#define NULL 0

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int sum = 0;
        ListNode *l3 = NULL;
        ListNode **node = &l3;
        while (l1 != NULL || l2 != NULL || sum > 0) {
            if (l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }
            if (sum > 9) {
                (*node) = new ListNode(sum - 10);
                sum = 1;
            } else {
                (*node) = new ListNode(sum);
                sum = 0;
            }
            node = &((*node)->next);
        }
        return l3;
    }
};

int main() {
    ListNode l1{1};
    ListNode l2{2};
    Solution solution;
    cout << solution.addTwoNumbers(&l1, &l2)->val << endl;
    return 0;
}

