/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution 
{
    long int max=0;
    long int M=1000000007;
    public:
    int addBT(TreeNode* root)
    {
        if (root==NULL)
        {
            return 0;
        }
        root->val=((addBT(root->left)%M)+(addBT(root->right)%M)+((root->val)%M)%M);
        return root->val;
    }
    // void display(TreeNode *root)
    // {
    //     if (root==NULL)
    //     {
    //         return;
    //     }
    //     display(root->left);
    //     cout<<root->val<<" ";
    //     display(root->right);
    // }
    void XYZ(TreeNode *root,long int totalSum)
    {
        if (root==NULL)
            return;
        if ((root->val)*(totalSum-(root->val))>max)
        {
            max=(root->val)*(totalSum-(root->val));
        }
        XYZ(root->left,totalSum);
        XYZ(root->right,totalSum);
    }
    int maxProduct(TreeNode* root) 
    {
        long int totalSum=addBT(root);
        //display(root);
        XYZ(root,totalSum);
        return max%M;
    }
};