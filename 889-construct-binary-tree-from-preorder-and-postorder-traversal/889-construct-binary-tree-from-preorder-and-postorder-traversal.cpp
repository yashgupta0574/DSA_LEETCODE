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
        map<int, int> mp;
    int n;
    void build(TreeNode *root, vector<int> &preorder, vector<int> &postorder, int idx, int val)
    {

        if (idx >= n) return;
        if (mp.find(preorder[idx]) == mp.end())
        {
            root->left = new TreeNode(preorder[idx]);
            mp[preorder[idx]]++;
        }
        else root->left = NULL;
        int i, j;
        for (i = 0; i < n; i++)
        {
            if (postorder[i] == val)
            {
                if (i == 0 || mp.find(postorder[i - 1]) != mp.end()) root->right = NULL;
                else root->right = new TreeNode(postorder[i - 1]);
                if (i != 0) mp[postorder[i - 1]]++;
                break;
            }
        }
        if (root->left != NULL) build(root->left, preorder, postorder, idx + 1, preorder[idx]);
        if (root->right != NULL)
        {
            for (j = 0; j < n; j++)
            {
                if (preorder[j] == postorder[i - 1]) break;
            }
            build(root->right, preorder, postorder, j + 1, postorder[i - 1]);
        }
    }

    TreeNode* constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
    {
        n = preorder.size();
        TreeNode *root = new TreeNode(preorder[0]);
        mp[preorder[0]]++;
        build(root, preorder, postorder, 1, preorder[0]);
        return root;
    }
};