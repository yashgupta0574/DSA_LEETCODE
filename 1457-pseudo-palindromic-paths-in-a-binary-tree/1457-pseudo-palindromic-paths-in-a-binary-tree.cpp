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
        int ans = 0;
    void checkpal(unordered_map<int, int> &mp)
    {
        if (mp.size() == 0) return;
        int odd = 0;
        for (auto it: mp)
        {
            if (it.second % 2) odd++;
            if (odd > 1) break;
        }
        if (odd < 2) ans++;
    }

    void calc(TreeNode *root, unordered_map<int, int> &mp)
    {
        mp[root->val]++;
        if (root->left == NULL && root->right == NULL)
        {
            checkpal(mp);
            mp[root->val]--;
            return;
        }
        if(root->left!=NULL) calc(root->left, mp);
        if(root->right!=NULL) calc(root->right, mp);
        mp[root->val]--;
    }

    int pseudoPalindromicPaths(TreeNode *root)
    {
        unordered_map<int, int> mp;
        if(root==NULL) return 0;
        calc(root, mp);
        return ans;
    }
};