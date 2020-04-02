class Solution 
{
    public:
    
    bool ans=false;
    
    bool hasPathSum(TreeNode* root, int sum) 
    {
        if (root==NULL)
        {
            return ans;
        }
        if (root->left)
        {
            root->left->val=(root->left->val)+(root->val);
        }
        if (root->right)
        {
            root->right->val=(root->right->val)+(root->val);
        }
        if (root->left==NULL && root->right==NULL && root->val==sum)
        {
            ans=true;
        }
        hasPathSum(root->left,sum);
        hasPathSum(root->right,sum);
        return ans;
    }
};