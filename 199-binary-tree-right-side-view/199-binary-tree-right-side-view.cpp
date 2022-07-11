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
    void helper(TreeNode* root,vector<int>& ans,int level)
    {
        if(root == NULL)
            return;
        if(ans.size()<=level)
            ans.push_back(root->val);
        helper(root->right,ans,level+1);
        helper(root->left,ans,level+1);
    }
    vector<int> rightSideView(TreeNode* root) 
    {
        if(root == NULL)
            return {};
        vector<int> ans;
        //BFS Approach
       
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while(q.size()!=0)
        {
            // int currSize = q.size();
            // TreeNode* currNode;
            // while(currSize--)
            // {
            //     currNode = q.front();
            //     q.pop();
            //     if(currNode->left != NULL)
            //         q.push(currNode->left);
            //     if(currNode->right != NULL)
            //         q.push(currNode->right);
            // }
            // ans.push_back(currNode->val);
            TreeNode *curr;
            if(q.front() != NULL)
            {
                curr = q.front();
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
                q.pop();
            }
            else
            {
                ans.push_back(curr->val);
                q.pop();
                if(q.size())
                    q.push(NULL);
            }
        }
        return ans;
        
        //DFS Approach
       /* helper(root,ans,0);
        return ans;
      */
        
        
    }
};