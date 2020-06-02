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


//Very good question, post order traversal,kadane implicit
class Solution 
{
    public:
    
    int result=INT_MIN,ms,m21;
    
    int helper(TreeNode *root)
    {
        if (root==NULL)
        {
            return 0;
        }
        int l,r;
        l=helper(root->left);
        r=helper(root->right);
        ms=max(root->val,root->val+max(l,r));//When node lies on path of maximum sum
        m21=max(ms,root->val+l+r);//When node itself is root of max sum path
        result=max(result,m21);
        return ms;
    }
    
    int maxPathSum(TreeNode* root) 
    {
        if (root==NULL)
        {
            return 0;
        }
        helper(root);
        return result;
    }
};