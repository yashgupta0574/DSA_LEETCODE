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
        int l, r;
    vector<TreeNode*> calc(int a, int b)
    {
        vector<TreeNode*> bst;
        if (b < a)
        {
            bst.push_back(NULL);
            return bst;
        }
        for (int i = a; i <= b; i++)
        {
            vector<TreeNode*> lefttree = calc(a, i - 1);
            vector<TreeNode*> righttree = calc(i + 1, b);
            l = lefttree.size();
            r = righttree.size();
            for (int j = 0; j < l; j++)
            {
                for (int k = 0; k < r; k++)
                {
                    TreeNode *root = new TreeNode(i);
                    root->right = righttree[k];
                    root->left = lefttree[j];
                    bst.push_back(root);
                }
            }
        }
        return bst;
    }
    vector<TreeNode*> generateTrees(int n)
    {
        vector<TreeNode*> ans = calc(1, n);
        return ans;
    }
};