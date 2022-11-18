/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *  int val;
 *  TreeNode * left;
 *  TreeNode * right;
 *  TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        int minimumOperations(TreeNode *root)
        {
            queue<TreeNode*> q;
            q.push(root);
            q.push(NULL);
            int ans = 0, pos;
            vector<int> v;
            while (!q.empty())
            {
                TreeNode *f = q.front();
                q.pop();
                if (f == NULL)
                {
                    vector<int> c = v;
                    sort(v.begin(), v.end());
                    for (int i = 0; i < v.size(); i++)
                    {
                        pos = lower_bound(v.begin(), v.end(), c[i]) - v.begin();
                        if (pos != i)
                        {
                            swap(c[i], c[pos]);
                            ans++;
                            i--;
                        }
                    }
                    if (q.empty()) break;
                    v.clear();
                    q.push(NULL);
                    continue;
                }
                v.push_back(f->val);
                if (f->left) q.push(f->left);
                if (f->right) q.push(f->right);
            }
            return ans;
        }
};