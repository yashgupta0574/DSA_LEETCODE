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
        ListNode* deleteDuplicates(ListNode *head)
        {
            if (head == NULL || head->next == NULL) return head;
            ListNode *prev = head;
            ListNode *curr = head;
            ListNode *top = head->next;
            bool flag = false;
            while (top != NULL && top->val == curr->val)
            {
                while (top != NULL && top->val == curr->val)
                {
                    top = top->next;
                }
                head = top;
                prev = curr;
                curr = top;
                if (top == NULL) break;
                top = top->next;
            }
            while (top != NULL)
            {
                while (top != NULL && top->val == curr->val)
                {
                    top = top->next;
                    flag = true;
                }
                if (flag)
                {
                    while (prev->next->val != curr->val)
                    {
                        prev = prev->next;
                    }
                    curr = top;
                    if(top!=NULL) top=top->next;
                    prev->next = curr;
                }
                if (top != NULL && !flag)
                {
                    top = top->next;
                    curr = curr->next;
                }
                else if(flag) flag=false;
            }
            return head;
        }
};