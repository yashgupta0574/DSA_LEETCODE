/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans=0;
    int sumOfLeftLeaves(TreeNode* root) {
        if(root->left==NULL and root->right==NULL) return 0;
        if(root->left && root->left->left==NULL && root->left->right==NULL) ans+=root->left->val;
        if(root->left) sumOfLeftLeaves(root->left);
        if(root->right && root->right->left!=NULL && root->right->right!=NULL) ans+=0;
        if(root->right && (root->right->left!=NULL || root->right->right!=NULL)) sumOfLeftLeaves(root->right);
        return ans;
    }
};