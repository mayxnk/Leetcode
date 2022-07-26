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
    queue<int> q;
    void helper(TreeNode* root)
    {
        if(root == NULL)
            return;
        helper(root->left);
        q.push(root->val);
        helper(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) 
    {
        helper(root);
        TreeNode* root1 = new TreeNode(q.front());
        TreeNode* root2 = root1;
        q.pop();
        while(!q.empty())
        {
            TreeNode* temp = new TreeNode(q.front());
            root1->right = temp;
            root1 = temp;
            q.pop();
        }
        return root2;
    }
};