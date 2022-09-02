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
    vector<double> averageOfLevels(TreeNode* root) 
    {
        vector<double> ans;
        queue<TreeNode*> pn;
        pn.push(root);
        while(pn.size())
        {
            int n = pn.size(),n1;
            n1 = n;
            double sum = 0;
            while(n--)
            {
                TreeNode* curr = pn.front();
                pn.pop();
                sum += curr->val;
                if(curr->left)
                    pn.push(curr->left);
                if(curr->right)
                    pn.push(curr->right);
            }
            double avg = (double)sum/n1;
            ans.push_back(avg);
        }
        return ans;
    }
};