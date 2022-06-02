#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *temp1 = head;
        ListNode *temp2 = head;
        int n = 0, i = 0;
        while (temp1 != NULL)
        {
            n++;
            temp1 = temp1->next;
        }
        while (i < n / 2)
        {
            i++;
            temp2 = temp2->next;
        }
        return temp2;
    }
};