/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) 
    {
        if(root == NULL)
            return {};
        vector<int> ans;
        //BFS Approach
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()!=0)
        {
            int currSize = q.size();
            TreeNode* currNode;
            while(currSize--)
            {
                currNode = q.front();
                q.pop();
                if(currNode->left != NULL)
                    q.push(currNode->left);
                if(currNode->right != NULL)
                    q.push(currNode->right);
            }
            ans.push_back(currNode->val);
        }
        return ans;
    }
};