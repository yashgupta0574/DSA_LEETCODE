/**
 *Definition for singly-linked list.
 *struct ListNode {
 *int val;
 *ListNode * next;
 *ListNode() : val(0), next(nullptr) {}
 *ListNode(int x) : val(x), next(nullptr) {}
 *ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        ListNode* removeNthFromEnd(ListNode *head, int n)
        {
            ListNode *temp = head;
            ListNode *a = head;
            int x = 0, dis;
            while (temp != NULL)
            {
                temp = temp->next;
                x++;
            }
            if (x == n)
            {
                head = head->next;
                return head;
            }
            dis = x - n - 1;
            while (dis--) a = a->next;
            a->next = a->next->next;
            return head;
        }
};