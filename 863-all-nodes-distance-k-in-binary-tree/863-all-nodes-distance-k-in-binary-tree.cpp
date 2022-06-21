/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *int val;
 *TreeNode * left;
 *TreeNode * right;
 *TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *};
 */
class Solution
{
    public:
        vector<int> ans;
    void nodes_down(TreeNode *root, int k)
    {
        if (root == NULL || k < 0) return;
        if (k == 0)
        {
            ans.push_back(root->val);
            return;
        }
        nodes_down(root->left, k - 1);
        nodes_down(root->right, k - 1);
    }

    int k_dist(TreeNode *root, TreeNode *target, int k)
    {
        if (root == NULL) return -1;
        if (root == target)
        {
            nodes_down(root, k);
            return 1;
        }
        int dl = k_dist(root->left, target, k);
        if (dl != -1)
        {
            if (dl == k)
            {
                ans.push_back(root->val);
            }
            else
            {
                nodes_down(root->right, k - dl - 1);
            }
            return 1 + dl;
        }
        int dr = k_dist(root->right, target, k);
        if (dr != -1)
        {
            if (dr == k)
            {
                ans.push_back(root->val);
            }
            else nodes_down(root->left, k - dr - 1);
            return 1 + dr;
        }
        return -1;
    }
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        k_dist(root, target, k);
        return ans;
    }
};