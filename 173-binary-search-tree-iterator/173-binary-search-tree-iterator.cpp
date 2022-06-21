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
class BSTIterator
{
    public:
        stack<int> st;
    int top;
    void rin(TreeNode *root)
    {
        if (root == NULL) return;
        rin(root->right);
        st.push(root->val);
        rin(root->left);
    }
    BSTIterator(TreeNode *root)
    {
        rin(root);
    }

    int next()
    {
        top = st.top();
        st.pop();
        return top;
    }

    bool hasNext()
    {
        return !st.empty();
    }
};

/**
 *Your BSTIterator object will be instantiated and called as such:
 *BSTIterator* obj = new BSTIterator(root);
 *int param_1 = obj->next();
 *bool param_2 = obj->hasNext();
 */