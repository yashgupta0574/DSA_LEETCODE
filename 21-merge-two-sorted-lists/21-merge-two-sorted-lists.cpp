/**
 *Definition for singly-linked list.
 *struct ListNode {
 *   int val;
 *   ListNode * next;
 *   ListNode() : val(0), next(nullptr) {}
 *   ListNode(int x) : val(x), next(nullptr) {}
 *   ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        ListNode* mergeTwoLists(ListNode *list1, ListNode *list2)
        {
            ListNode *ptr1 = list1;
            ListNode *ptr2 = list2;
            ListNode *ptr3=new ListNode(-1);
            ListNode *dummynode = ptr3;
            while (ptr1 != NULL and ptr2 != NULL)
            {
                if (ptr1->val < ptr2->val)
                {
                    dummynode->next = ptr1;
                    ptr1 = ptr1->next;
                }
                else
                {
                    dummynode->next = ptr2;
                    ptr2 = ptr2->next;
                }
                dummynode = dummynode->next;
            }
            if(ptr1!=NULL) dummynode->next=ptr1;
            else if(ptr2!=NULL) dummynode->next=ptr2;
            return ptr3->next;
        }
};