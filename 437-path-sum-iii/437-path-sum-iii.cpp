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
        int ans = 0, t;
    void calc(TreeNode *root,long long int sum)
    {
        if (root == NULL) return;
        if(sum==root->val) ans++;
        calc(root->left,sum-root->val);
        calc(root->right,sum-root->val);
    }

    int pathSum(TreeNode *root, int targetSum)
    {
        if(root==NULL) return 0;
        calc(root,targetSum);
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);
        return ans;
    }
};