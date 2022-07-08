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
        ListNode* mergeKLists(vector<ListNode*> &lists)
        {
            int n = lists.size();
            if(n==0) return NULL;
           vector<int>v;
            for (auto ii: lists)
            {
                while(ii!=NULL)
                {
                    v.push_back(ii->val);
                    ii=ii->next;
                }
            }
            if(v.size()==0) return NULL;
            sort(v.begin(),v.end());
            ListNode *head = new ListNode(v[0]);
            ListNode *temp = head;
            int l=v.size();
            for (int i = 1; i < l; i++)
            {
                temp->next = new ListNode(v[i]);
                temp = temp->next;
            }
            return head;
        }
};