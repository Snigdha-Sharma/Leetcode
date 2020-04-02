class Solution 
{
    public:
    
    int ans=0,l,r;
    void inorder(TreeNode *root)
    {
        if (root==NULL)
        {
            return;
        }
        inorder(root->left);
        if (root->val>=l && root->val<=r)
        {
            ans=ans+root->val;
        }
        inorder(root->right);
    }
    
    int rangeSumBST(TreeNode* root, int L, int R) 
    {
        l=L;
        r=R;
        inorder(root);
        return ans;
    }
};