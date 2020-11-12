//
// Created by Михаил Степанов on 01.11.2020.
//

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
    static int getDecimalValue(ListNode *head)
    {
        int decimal = 0;
        while (head) {
            decimal *= 2;
            decimal += head->val;
            head = head->next;
        }
        return decimal;
    }
};

#include <iostream>

using namespace std;

int main () {

    return 0;
}
