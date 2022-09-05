/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution
{
    public:
        vector<vector < int>> levelOrder(Node *root)
        {
            vector<vector < int>>ans;
            if(!root) return ans;
            queue<Node*> q;
            q.push(root);
            q.push(NULL);
            vector<int>a;
            while (!q.empty())
            {
                Node *tmp = q.front();
                q.pop();
                if (tmp == NULL)
                {
                    ans.push_back(a);
                    a.clear();
                    if (q.empty()) break;
                    q.push(NULL);
                    continue;
                }
                a.push_back(tmp->val);
                int sz = tmp->children.size();
                for (int i = 0; i < sz; i++)
                {
                    q.push(tmp->children[i]);
                }
            }
            return ans;
        }
};