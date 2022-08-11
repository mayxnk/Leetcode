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
    bool checkBST(TreeNode* root,long val1,long val2)
    {
        if(root == NULL)
            return true;
        
        
        if(root->val <= val1 or root->val >= val2)
            return false;
        return checkBST(root->left,val1,root->val)and checkBST(root->right,root->val,val2);
    }
    bool isValidBST(TreeNode* root) 
    {
//         if(root == NULL)
//             return true;
        
//         if(root->right)
//             if(root->right->val < root->val)
//                 return false;
//         if(root->left and root->left->val > root->val)
//             return false;
        
//         return isValidBST(root->left) and isValidBST(root->right);
        if(!root->right and !root->left)
            return true;
        return checkBST(root,LONG_MIN,LONG_MAX);
        
    }
};