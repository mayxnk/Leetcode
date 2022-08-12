/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void helper(TreeNode* root,int a,int b,TreeNode*& ans)
    {
        if(root == NULL)
            return;
        if(root->val == a || root->val == b)
        {
            ans = root;
            return;
        }
        if(a < root->val and b < root->val)
            return helper(root->left,a,b,ans);
        else if(a > root->val)
            return helper(root->right,a,b,ans);
        else
        {
            ans = root;
            return;
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        int a = min(p->val,q->val);
        int b = max(p->val,q->val);
        TreeNode* ans;
        helper(root,a,b,ans);
        return ans;
    }
};