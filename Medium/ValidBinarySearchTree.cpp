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
class Solution 
{
    public:
    
    bool helper(TreeNode *root,long long int lval,long long int rval)
    {
        if (root==NULL)
        {
            return true;
        }
        long long int val=(long long int)root->val;
        if (val>=lval && val<=rval)
        {
            return (helper(root->left,lval,val-1) && helper(root->right,val+1,rval));
        }
        return false;
    }
    
    bool isValidBST(TreeNode* root) 
    {
        long long int val=(long long int)root->val;
        long int LONGINT_MIN=-2147483648,LONGINT_MAX=2147483647;
        if (root==NULL)
        {
            return true;
        }
        return (helper(root->left,LONGINT_MIN,val-1) && helper(root->right,val+1,LONGINT_MAX));
    }
};