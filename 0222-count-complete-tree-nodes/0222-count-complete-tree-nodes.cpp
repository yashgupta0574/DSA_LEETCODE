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
        int last_nodes = 0,depth=0;
    void cnt(TreeNode *root,int d)
    {
        if (!root->left && !root->right && d==depth)
        {
            last_nodes++;
            return;
        }
        if (root->left) cnt(root->left,d+1);
        if (root->right) cnt(root->right,d+1);
    }
    int countNodes(TreeNode *root)
    {
        if (!root) return 0;
        TreeNode *tmp = root;
        while (tmp->left)
        {
            depth++;
            tmp = tmp->left;
        }
        cnt(root,0);
        return last_nodes + pow(2, depth) - 1;
    }
};