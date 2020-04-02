class Solution 
{
    public:
    
    int height(TreeNode *root)
    {
        if (root==NULL)
        {
            return 0;
        }
        return max(height(root->left),height(root->right))+1;
    }
    
    bool isBalanced(TreeNode* root) 
    {
        if (root==NULL)
        {
            return true;
        }
        int lh,rh;
        lh=height(root->left);
        rh=height(root->right);
        if (abs(rh-lh)<=1 && isBalanced(root->left) && isBalanced(root->right))
        {
            return true;
        }
        return false;
    }
};