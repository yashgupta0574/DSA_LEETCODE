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
        bool verify(TreeNode *root, TreeNode *subRoot)
        {
            if (root == NULL && subRoot == NULL) return true;
            if (root == NULL || subRoot == NULL) return false;
            if (root->val != subRoot->val) return false;
            bool ls, rs;
            ls = verify(root->left, subRoot->left);
            rs = verify(root->right, subRoot->right);
            if (ls == true && rs == true && root->val==subRoot->val) return true;
            return false;
        }

    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if (root == NULL && subRoot == NULL) return true;
        bool ls = false, rs = false;
        if (root == NULL) return false;
        if (root->val == subRoot->val && verify(root, subRoot)) return true;
        ls = isSubtree(root->left, subRoot);
        rs = isSubtree(root->right, subRoot);
        if (ls == true || rs == true) return true;
        return false;
    }
};