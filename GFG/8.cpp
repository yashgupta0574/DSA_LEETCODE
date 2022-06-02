//https://practice.geeksforgeeks.org/problems/count-bst-nodes-that-lie-in-a-given-range/1

#include <bits/stdc++.h>
using namespace std;

vector<int> inorder(Node *root, vector<int> &v)
{
    if (root == NULL)
    {
        v.push_back(0);
        return v;
    }
    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
    return v;
}
int getCount(Node *root, int l, int h)
{
   vector<int> v;
    v = inorder(root, v);
    int count=0;
    for(auto i:v){
        if(i>=l && i<=h){
            count ++;
        }
    }
    return count;
}
