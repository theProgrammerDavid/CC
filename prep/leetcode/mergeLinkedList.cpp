
#include <bits/stdc++.h>
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {

        ListNode *nh = new ListNode(-1);
        ListNode *t = nh;

        while (l1 != NULL && l2 != NULL)
        {
            if (l1->val <= l2->val)
            {
                t->next = l1;
                l1 = l1->next;
            }
            else
            {
                t->next = l2;
                l2 = l2->next;
            }

            t = t->next;
        }

        t->next = l1 == NULL ? l2 : l1;

        return nh->next;
    }
};