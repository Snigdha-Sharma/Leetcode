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
    
    int height(TreeNode *root)
    {
        if (root==NULL)
        {
            return 0;
        }
        return 1+max(height(root->left),height(root->right));
    }
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) 
    {
        if (root==NULL)
        {
            return root;
        }
        int lHeight=height(root->left);
        int rHeight=height(root->right);
        if (lHeight==rHeight)
        {
            return root;
        }
        if (lHeight>rHeight)
        {
            return lcaDeepestLeaves(root->left);
        }
        else
        {
            return lcaDeepestLeaves(root->right);
        }
        return NULL;
    }
};