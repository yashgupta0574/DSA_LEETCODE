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
        TreeNode* invertTree(TreeNode *root)
        {
            if (root == NULL) return NULL;
            invertTree(root->left);
            invertTree(root->right);
            TreeNode *temp = root->left;
            root->left = root->right;
            root->right = temp;
            return root;
        }

    bool verify(TreeNode *root, TreeNode *subRoot)
    {
        if (root == NULL && subRoot == NULL) return true;
        if (root == NULL || subRoot == NULL) return false;
        if (root->val != subRoot->val) return false;
        bool ls, rs;
        ls = verify(root->left, subRoot->left);
        rs = verify(root->right, subRoot->right);
        if (ls == true && rs == true && root->val == subRoot->val) return true;
        return false;
    }

    bool isSymmetric(TreeNode *root) {
        if(root==NULL) return true;
        if(root->left!=NULL and root->right==NULL) return false;
        if(root->left==NULL and root->right!=NULL) return false;
        invertTree(root->right);
        return verify(root->left,root->right);
    }
};