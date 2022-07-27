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
    bool hasPath(TreeNode* root,TreeNode* a,vector<TreeNode*>& arr)
    {
        if(root == NULL)
            return false;
        arr.push_back(root);
        if(root == a)
            return true;
        if(hasPath(root->right,a,arr) || hasPath(root->left,a,arr))
            return true;
        
        arr.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        //Using extra space
        if(root == NULL)
            return NULL;
        vector<TreeNode*> arr1;
        vector<TreeNode*> arr2;
        
        hasPath(root,p,arr1);
        hasPath(root,q,arr2);
        TreeNode* prev = root;
        int i = 0,j = 0;
        while(i<arr1.size() and j<arr2.size() and arr1[i] == arr2[j])
        {
            prev = arr1[i];
            ++i;
            ++j;
        }
        return prev;
    }
};