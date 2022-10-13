/**
 *Definition for singly-linked list.
 *struct ListNode {
 *   int val;
 *   ListNode * next;
 *   ListNode(int x) : val(x), next(NULL) {}
 *};
 */
class Solution
{
    public:
        void deleteNode(ListNode *node)
        {
            ListNode *temp = node->next;
            int v;
            while (temp != NULL)
            {
                v = temp->val;
                node->val = v;
                if (!temp->next) node->next = NULL;
                node = temp;
                temp = temp->next;
            }
            delete node;
        }
};