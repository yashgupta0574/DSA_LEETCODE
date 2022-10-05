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
        void add(TreeNode *root, int val, int depth)
        {
            if(root==NULL) return;
            if (depth == 2)
            {
                TreeNode *l = new TreeNode(val);
                TreeNode *r = new TreeNode(val);
                TreeNode* tmpl=root->left;
                TreeNode* tmpr=root->right;
                root->left=l;
                root->right=r;
                l->left = tmpl;
                r->right=tmpr;
                return;
            }
            add(root->left,val,depth-1);
            add(root->right,val,depth-1);
        }

    TreeNode* addOneRow(TreeNode *root, int val, int depth)
    {
        if (depth == 1)
        {
            TreeNode *l = new TreeNode(val);
            l->left = root;
            return l;
        }
        add(root, val, depth);
        return root;
    }
};