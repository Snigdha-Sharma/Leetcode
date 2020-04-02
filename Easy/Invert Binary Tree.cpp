class Solution 
{
    public:
    
    TreeNode *temp;
    
    TreeNode* invertTree(TreeNode* root) 
    {
        if (root==NULL)
        {
            return root;
        }
        temp=root->left;
        root->left=root->right;
        root->right=temp;
        root->left=invertTree(root->left);
        root->right=invertTree(root->right);
        return root;
    }
};