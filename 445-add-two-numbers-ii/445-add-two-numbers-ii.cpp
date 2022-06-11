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
        ListNode* reverse(ListNode* &head)
        {
            if (head->next == NULL) return head;
            ListNode *prev = NULL;
            ListNode *curr = head;
            ListNode *next1 = head->next;
            while (curr != NULL)
            {
                next1 = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next1;
            }
            return prev;
        }

    int length(ListNode *head)
    {
        int ans = 0;
        ListNode *temp = head;
        while (temp != NULL)
        {
            temp = temp->next;
            ans++;
        }
        return ans;
    }
    ListNode* addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int a = length(l1), b = length(l2), prev = 0, p;
        ListNode *head1 = reverse(l1);
        ListNode *head2 = reverse(l2);
       	// while (head2 != NULL)
       	// {
       	//     cout << head2->val;
       	//     head2 = head2->next;
       	// }
        if (a > b)
        {
            ListNode *ans = head1;
            while (b--)
            {
                p = head1->val + head2->val + prev;
                prev = p / 10;
                head1->val = p % 10;
                head1 = head1->next;
                head2 = head2->next;
            }
            while (head1->next != NULL)
            {
                cout << 16;
                p = head1->val + prev;
                prev = p / 10;
                head1->val = p % 10;
                head1 = head1->next;
            }
            p = head1->val + prev;
            prev = p / 10;
            head1->val = p % 10;
            if (prev != 0)
            {
                head1->next = new ListNode(prev);
                head1 = head1->next;
            }
            // ListNode *ans = reverse(head1);
            // while (ans != NULL)
            // {
            //     cout << ans->val;
            //     ans = ans->next;
            // }
            return reverse(ans);
        }
        else if (b > a)
        {
            ListNode *ans = head2;
            while (a--)
            {
                p = head2->val + head1->val + prev;
                prev = p / 10;
                head2->val = p % 10;
                head1 = head1->next;
                head2 = head2->next;
            }

            while (head2->next != NULL)
            {
                p = head2->val + prev;
                prev = p / 10;
                head2->val = p % 10;
                head2 = head2->next;
            }
            p = head2->val + prev;
            prev = p / 10;
            head2->val = p % 10;
            if (prev != 0)
            {
                head2->next = new ListNode(prev);
                head2 = head2->next;
            }
            return reverse(ans);
        }
        else
        {
            ListNode *ans = head1;
            while (head1->next != NULL)
            {
                p = head1->val + head2->val + prev;
                prev = p / 10;
                head1->val = p % 10;
                head1 = head1->next;
                head2 = head2->next;
            }
            p = head1->val + head2->val + prev;
            prev = p / 10;
            head1->val = p % 10;
            if (prev != 0)
            {
                head1->next = new ListNode(prev);
                head1 = head1->next;
            }
            return reverse(ans);
        }
        return head1;
    }
};