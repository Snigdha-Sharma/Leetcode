class Solution 
{
    public:
    
    int sum=0;
    
    int sumOfLeftLeaves(TreeNode* root) 
    {
        if (root==NULL)
        {
            return 0;
        }
        if (root->left && root->left->left==NULL && root->left->right==NULL)
        {
            sum=sum+root->left->val;
        }
        sumOfLeftLeaves(root->left);
        sumOfLeftLeaves(root->right);
        return sum;
    }
};