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
    int n;
    TreeNode* buildBST(vector<int> &nums, int mn, int mx)
    {
        if (mn > mx) return NULL;
        int mid = (mn + mx) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = buildBST(nums, mn, mid - 1);
        root->right = buildBST(nums, mid + 1, mx);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int> &nums)
    {
        n = nums.size();
        return buildBST(nums, 0, n - 1);
    }
};