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
        TreeNode *temp, *temp1;
    void flatten(TreeNode *root)
    {
        if (root == NULL) return;
        flatten(root->left);
        flatten(root->right);
        cout<<root->val;
        temp = root->right;
        root->right = root->left;
        root->left=NULL;
        temp1 = root;
        while (temp1->right != NULL) temp1 = temp1 -> right;
        temp1->right=temp;
    }
};