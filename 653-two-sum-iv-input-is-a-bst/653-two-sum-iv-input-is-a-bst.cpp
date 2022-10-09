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
        unordered_map<int, int> mp;
    int k;
    bool flag = false;
    void calc(TreeNode *root)
    {
        if (flag || !root) return;
        if (mp.find(k - root->val) != mp.end())
        {
            flag = true;
            return;
        }
        mp[root->val]++;
        calc(root->left);
        calc(root->right);
    }

    bool findTarget(TreeNode *root, int k)
    {
        this->k = k;
        calc(root);
        return flag;
    }
};