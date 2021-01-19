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
    
    TreeNode *newRoot=NULL,*x;
    
    void inorder(TreeNode* root)
    {
        if (root==NULL)
        {
            return;
        }
        inorder(root->left);
        if(newRoot==NULL)
        {
            newRoot=new TreeNode(root->val);
            x=newRoot;
        }
        else
        {
            newRoot->right=new TreeNode(root->val);
            newRoot->left=NULL;
            newRoot=newRoot->right;
        }
        
        inorder(root->right);
    }
    
    TreeNode* increasingBST(TreeNode* root) 
    {
        inorder(root);
        return x;
    }
};