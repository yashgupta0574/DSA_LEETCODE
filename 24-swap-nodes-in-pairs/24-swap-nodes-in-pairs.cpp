/**
 *Definition for singly-linked list.
 *struct ListNode {
 *    int val;
 *    ListNode * next;
 *    ListNode() : val(0), next(nullptr) {}
 *    ListNode(int x) : val(x), next(nullptr) {}
 *    ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        ListNode* swapPairs(ListNode *head)
        {
            if (!head || !head->next) return head;
            ListNode *prev = head, *curr = head->next, *temp = curr;
            prev->next = swapPairs(curr->next);
            curr->next = prev;
            prev = prev->next;
            if (prev != NULL) curr = prev->next;
            return temp;
        }
};