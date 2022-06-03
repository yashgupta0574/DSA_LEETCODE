#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *hare = head;
        ListNode *tor = head;
        while (tor != NULL && tor->next != NULL)
        {
            tor = tor->next->next;
            hare = hare->next;
            if (hare == tor)
                return true;
        }
        return false;
    }
};