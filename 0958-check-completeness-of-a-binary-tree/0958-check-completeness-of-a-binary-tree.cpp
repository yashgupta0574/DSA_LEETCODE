/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *   int val;
 *   TreeNode * left;
 *   TreeNode * right;
 *   TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        bool isCompleteTree(TreeNode *root)
        {
            queue<TreeNode*> q;
            q.push(root);
            q.push(NULL);
            bool lastLevel = false, end = false;
            int level = 1;
            while (!q.empty())
            {
                TreeNode *tmp = q.front();
                q.pop();
                if (tmp == NULL)
                {
                    if (q.empty()) return true;
                    if (pow(2, level) != q.size()) lastLevel = true;
                    tmp = q.front();
                    q.pop();
                    q.push(NULL);
                    level++;
                }
                if (lastLevel != true)
                {
                    if (end && (tmp->left || tmp->right)) return false;
                    if (tmp->left && tmp->right)
                    {
                        q.push(tmp->left);
                        q.push(tmp->right);
                    }
                    else if (!tmp->left && tmp->right) return false;
                    else if (tmp->left && !tmp->right)
                    {
                        end = true;
                        q.push(tmp->left);
                    }
                    else end = true;
                }
                else
                {
                    if (tmp->left || tmp->right) return false;
                }
            }
            return true;
        }
};