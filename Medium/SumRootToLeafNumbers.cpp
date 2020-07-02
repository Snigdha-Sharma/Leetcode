class Solution 
{
    public:
    
    int sum=0,num=0;
    
    void helper(TreeNode *root)
    {
        if (root==NULL)
        {
            return;
        }
        num=(num*10)+(root->val);
        //cout<<"num="<<num<<" ";
        if (root->left==NULL && root->right==NULL)
        {
            sum=sum+num;
            num=num/10;
            return;
        }
        
        helper(root->left);
        helper(root->right);
        num=num/10;
    }
    
    int sumNumbers(TreeNode* root) 
    {
        helper(root);
        return sum;
    }
};