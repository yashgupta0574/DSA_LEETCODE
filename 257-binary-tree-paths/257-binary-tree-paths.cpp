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
        vector<string> ans;
    void calc(TreeNode *root, string s)
    {
        if (root->left == NULL and root->right == NULL)
        {
            s += '-';
            s += '>';
            s += to_string(root->val);
            ans.push_back(s);
            return;
        }
        s += '-';
        s += '>';
        s += to_string(root->val);
        if (root->left != NULL) calc(root->left, s);
        if (root->right != NULL) calc(root->right, s);
    }
    vector<string> binaryTreePaths(TreeNode *root)
    {
        string s = "";
        s += to_string(root->val);
        if(root->left==NULL and root->right==NULL) return {s};
        if (root->left != NULL) calc(root->left, s);
        if (root->right != NULL) calc(root->right, s);
        return ans;
    }
};