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

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) 
    {
        if(root == NULL)
            return {};
        queue<Node*> pn;
        pn.push(root);
        vector<vector<int>> ans;
        while(pn.size())
        {
            int n = pn.size();
            vector<int> t;
            while(n--)
            {
                Node* curr = pn.front();
                pn.pop();
                t.push_back(curr->val);
                for(int i = 0;i<curr->children.size();i++)
                    pn.push(curr->children[i]);
            }
            ans.push_back(t);
        }
        return ans;
    }
    
};