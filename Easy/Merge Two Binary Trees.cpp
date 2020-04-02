class Solution 
{
    public:

    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) 
    {
        if (t1==NULL && t2==NULL)
        {
            return NULL;
        }
        else if (t1==NULL)
        {
            TreeNode *curr=new TreeNode(t2->val);
            curr->left=mergeTrees(NULL,t2->left);
            curr->right=mergeTrees(NULL,t2->right);
            return curr;
        }
        else if (t2==NULL)
        {
            TreeNode *curr=new TreeNode(t1->val);
            curr->left=mergeTrees(t1->left,NULL);
            curr->right=mergeTrees(t1->right,NULL);
            return curr;
        }
        else
        {
            TreeNode *curr=new TreeNode(t1->val+t2->val);
            curr->left=mergeTrees(t1->left,t2->left);
            curr->right=mergeTrees(t1->right,t2->right);
            return curr;
        }
    }
};