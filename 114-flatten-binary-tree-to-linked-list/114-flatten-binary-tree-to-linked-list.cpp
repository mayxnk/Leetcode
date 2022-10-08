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
    void helper(TreeNode* root,vector<TreeNode*>& v)
    {
        if(root == NULL)
            return;
        v.push_back(root);
        helper(root->left,v);
        helper(root->right,v);
    }
    void flatten(TreeNode* root)
    {
//         if(root == NULL)
//             return;
//         TreeNode* root1 = NULL;
//         vector<TreeNode*> v;
//         helper(root,v);
        
//         int i = 0;
//         for(i = 0;i<v.size()-1;++i)
//         {
//             v[i]->right = v[i+1];
//             v[i]->left = NULL;
//         }
//         v[i]->right = NULL;
//         v[i]->left = NULL;
//         return;
        /* Morris Traversal - O(n),O(1)*/
        TreeNode *curr = root;
        while(curr)
        {
            if(curr->left)
            {
                TreeNode* temp = curr->left;
                while(temp->right)
                    temp = temp->right;
                temp->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }
};