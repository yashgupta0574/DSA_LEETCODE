// https://practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> inorder(Node *root, vector<int> &v)
    {
        if (root == NULL)
        {
            return v;
        }
        inorder(root->left, v);
        v.push_back(root->data);
        inorder(root->right, v);
        return v;
    }

    int kthLargest(Node *root, int K)
    {
        vector<int> v;
        v = inorder(root, v);
        int len = v.size();
        return v[len - K];
    }
};