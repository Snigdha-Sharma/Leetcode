class Solution 
{
    public:
    
    int ans=0;
    
    int height(TreeNode *root)
    {
        if (root==NULL)
        {
            return 0;
        }
        return max(height(root->left),height(root->right))+1;
    }
    
    int diameter(TreeNode *root)
    {
        if (root==NULL)
        {
            return 0;
        }
        int l=diameter(root->left);
        int r=diameter(root->right);
        ans=max(ans,l+r);
        return max(height(root->left),height(root->right))+1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) 
    {
        diameter(root);
        return ans;
    }
};