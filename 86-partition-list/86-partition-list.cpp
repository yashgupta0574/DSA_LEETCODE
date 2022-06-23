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
        ListNode* partition(ListNode *head, int x)
        {
            queue<int> mn;
            queue<int> mx;
            ListNode *temp = head;
            while (temp != NULL)
            {
                if (temp->val < x) mn.push(temp->val);
                else mx.push(temp->val);
                temp = temp->next;
            }
            temp = head;
            while (temp != NULL)
            {
                if (!mn.empty())
                {
                    temp->val = mn.front();
                    mn.pop();
                }
                else
                {
                    temp->val = mx.front();
                    mx.pop();
                }
                temp = temp->next;
            }
            return head;
        }
};