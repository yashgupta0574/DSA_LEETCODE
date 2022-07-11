/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
    public:
        vector<int> rightSideView(TreeNode *root)
        {
            if (root == NULL) return {};
            queue<TreeNode*> q;
            q.push(root);
            q.push(NULL);
            vector<int> ans;
            TreeNode * x;
            while (!q.empty())
            {
                x = q.front();
                q.pop();
                if (x->left) q.push(x->left);
                if (x->right) q.push(x->right);
                if (q.front() == NULL || q.empty())
                {
                    q.pop();
                    if (q.empty())
                    {
                        ans.push_back(x->val);
                        break;
                    }
                    ans.push_back(x->val);
                    q.push(NULL);
                }
            }
            return ans;
        }
};