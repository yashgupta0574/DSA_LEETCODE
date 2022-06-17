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
        int ans = 0;
    int calc(TreeNode *root)
    {
        if (!root) return 1;
        int x = calc(root->left);
        int y = calc(root->right);
        if (x == 0 || y == 0)
        {
            ans++;
            return 2;
        }
        if (x == 1 && y == 1) return 0;
        return 1;
    }
    int minCameraCover(TreeNode *root)
    {
        int a1 = calc(root);
        if (a1 == 0) ans++;
        return ans;
    }
};