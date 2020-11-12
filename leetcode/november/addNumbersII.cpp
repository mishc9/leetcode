//
// Created by Михаил Степанов on 08.11.2020.
//

#include <stack>

using namespace std;

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

    static void toStack(ListNode *head, stack<int> &s)
    {
        while (head != nullptr) {
            s.push(head->val);
            head = head->next;
        }
    }

    static ListNode *toList(stack<int> stack)
    {
        ListNode *head = NULL;
        ListNode *temp = NULL;

        while (stack.size()) {
            int x = stack.top();
            stack.pop();

            auto *newNode = new ListNode(x);

            if (head == nullptr) {
                head = newNode;
                temp = head;
            } else {
                temp->next = newNode;
                temp = temp->next;
            }
        }

        return head;
    }

    static ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {

        stack<int> stackOne;
        stack<int> stackTwo;
        stack<int> ans;

        toStack(l1, stackOne);
        toStack(l2, stackTwo);

        int carryVal = 0;

        while (!stackOne.empty() and !stackTwo.empty()) {
            int x = stackOne.top();
            int y = stackTwo.top();

            stackOne.pop();
            stackTwo.pop();

            int sum = x + y + carryVal;
            ans.push(sum % 10);
            carryVal = sum / 10;
        }

        while (!stackOne.empty()) {
            int top = stackOne.top();
            stackOne.pop();
            int sum = top + carryVal;

            ans.push(sum % 10);

            carryVal = sum / 10;
        }

        while (!stackTwo.empty()) {
            int top = stackTwo.top();
            stackTwo.pop();
            int sum = top + carryVal;
            ans.push(sum % 10);

            carryVal = sum / 10;
        }

        if (carryVal == 1) { ans.push(1); }

        return toList(ans);
    }
};
