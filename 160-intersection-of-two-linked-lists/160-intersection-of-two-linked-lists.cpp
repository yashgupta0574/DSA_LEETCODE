/**
 *Definition for singly-linked list.
 *struct ListNode {
 *  int val;
 *  ListNode * next;
 *  ListNode(int x) : val(x), next(NULL) {}
 *};
 */
class Solution
{
    public:
        ListNode* getIntersectionNode(ListNode *headA, ListNode *headB)
        {
            int l1 = 0, l2 = 0, diff = 0;
            ListNode *temp1 = headA;
            ListNode *temp2 = headB;
            ListNode *temp3 = headA;
            ListNode *temp4 = headB;
            while (temp1 != NULL)
            {
                temp1 = temp1->next;
                l1++;
            }
            while (temp2 != NULL)
            {
                temp2 = temp2->next;
                l2++;
            }
            if (l1 > l2)
            {
                diff = l1 - l2;
                while (diff--) temp3 = temp3->next;
            }
            else
            {
                diff = l2 - l1;
                while (diff--) temp4 = temp4->next;
            }
            if (temp3 == temp4) return temp3;
            while (temp3 != temp4 || temp3 != NULL)
            {
                temp3 = temp3->next;
                temp4 = temp4->next;
                if (temp3 == temp4) return temp3;
            }
            return NULL;
        }
};