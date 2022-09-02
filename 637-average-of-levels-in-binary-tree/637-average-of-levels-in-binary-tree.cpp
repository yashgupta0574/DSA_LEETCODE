/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *int val;
 *TreeNode * left;
 *TreeNode * right;
 *TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        vector<double> averageOfLevels(TreeNode *root)
        {
            vector<double> ans;
            queue<TreeNode*> q;
            q.push(root);
            q.push(NULL);
            double sm = 0, cnt = 0;
            while (!q.empty())
            {
                TreeNode *t = q.front();
                q.pop();
                if (t == NULL)
                {
                    ans.push_back(double(sm) / cnt);
                    sm = 0;
                    cnt = 0;
                    if (q.empty()) return ans;
                    q.push(NULL);
                }
                else
                {
                    sm += t->val;
                    cnt++;
                    if (t->left)
                    {
                        q.push(t->left);
                    }
                    if (t->right)
                    {
                        q.push(t->right);
                    }
                }
            }
            return ans;
        }
};