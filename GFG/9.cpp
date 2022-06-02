// https://practice.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1

#include <bits/stdc++.h>
using namespace std;

int KthSmallestElement(Node *root, int K)
{
    vector<int> v;
    v = inorder(root, v);
    int len = v.size();
    if (K > len)
    {
        return -1;
    }
    return v[K - 1];
}
