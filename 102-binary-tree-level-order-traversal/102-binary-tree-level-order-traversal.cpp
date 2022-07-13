/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        vector<vector < int>> levelOrder(TreeNode *root)
        {
            if (root == NULL) return {};
            queue<TreeNode*> q;
            q.push(root);
            q.push(NULL);
            vector<vector < int>> ans;
            TreeNode * x;
            vector<int> v;
            while (!q.empty())
            {
                x = q.front();
                q.pop();
                if (x->left) q.push(x->left);
                if (x->right) q.push(x->right);
                v.push_back(x->val);
                if (q.front() == NULL || q.empty())
                {
                    q.pop();
                    ans.push_back(v);
                    v.resize(0);
                    if (q.empty()) break;
                    q.push(NULL);
                }
            }
            return ans;
        }
};