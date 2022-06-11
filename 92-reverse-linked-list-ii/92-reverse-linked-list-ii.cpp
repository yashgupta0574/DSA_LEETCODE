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
        ListNode* reverse(ListNode* &r, ListNode* &head, int diff)
        {
            ListNode *prev = r;
            ListNode *curr = head;
            ListNode* next1=NULL;
            while (diff--)
            {
                next1 = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next1;
            }
            return prev;
        }
    ListNode* reverseBetween(ListNode *head, int left, int right)
    {
        if(head->next==NULL) return head;
        ListNode *strnode = head;
        ListNode *r = head;
        int temp = right,temp1=left;
        temp1-=2;
        while (temp1>0)
        {
            head = head->next;
            temp1--;
        }
        while (temp--) r = r->next;
        if(left==1) return reverse(r, head, right - left+1);
        head->next = reverse(r, head->next, right - left+1);
        return strnode;
    }
};