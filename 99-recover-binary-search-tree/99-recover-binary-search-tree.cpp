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
        void swap(int *a, int *b)
        {
            int temp = *a;
            *a = *b;
            *b = temp;
        }

    void recoverBST(TreeNode *root, TreeNode **first, TreeNode **mid, TreeNode **last, TreeNode **prev)
    {
        if (root == NULL) return;
        recoverBST(root->left, first, mid, last, prev);
        if (*prev && (*prev)->val > root->val)
        {
            if (! *first)
            {
                *first = *prev;
                *mid = root;
            }
            else
            {
                *last = root;
            }
        }
        *prev = root;
        recoverBST(root->right, first, mid, last, prev);
    }

    void recoverTree(TreeNode *root)
    {
        TreeNode *first = NULL, *mid = NULL, *last = NULL, *prev = NULL;
        recoverBST(root, &first, &mid, &last, &prev);
        if (first && last) swap(&(first->val), &(last->val));
        else swap(&(first->val), &(mid->val));
    }
};