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
        int ans = INT_MIN;

    int calc(TreeNode *root)
    {
        if (root == NULL) return 0;
        int lsum = calc(root->left);
        int rsum = calc(root->right);
        int curr_ans = root->val;
        if (lsum > 0) curr_ans += lsum;
        if (rsum > 0) curr_ans += rsum;
        ans = max({ ans,curr_ans });
        return max({root->val + lsum, root->val + rsum,0});
    }

    int maxPathSum(TreeNode *root)
    {
        if (root == NULL) return 0;
        calc(root);
        return ans;
    }
};