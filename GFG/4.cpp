// https://practice.geeksforgeeks.org/problems/check-for-bst/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to check whether a Binary Tree is BST or not.
    bool isBST(Node *root, int min = INT_MIN, int max = INT_MAX)
    {
        if (root == NULL)
        {
            return true;
        }
        if (root->data < min || root->data > max)
        {
            return false;
        }
        bool leftBST = isBST(root->left, min, root->data - 1);
        bool rightBST = isBST(root->right, root->data + 1, max);

        return leftBST && rightBST;
    }
};