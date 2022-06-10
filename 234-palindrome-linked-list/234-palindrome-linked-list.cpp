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
        bool isPalindrome(ListNode *head)
        {
            stack<int> s;
            ListNode *temp = head;
            ListNode *temp1 = head;
            while (temp != NULL)
            {
                s.push(temp->val);
                temp = temp->next;
            }
            while (temp1 != NULL)
            {
                if (s.top() != temp1->val) return false;
                s.pop();
                temp1 = temp1->next;
            }
            return true;
        }
};