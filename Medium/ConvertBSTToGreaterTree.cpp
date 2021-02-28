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
class Solution 
{
    public:
    
    int cursum=0;
    void reverseInorder(TreeNode *root)
    {
        if (root->right)
        {
            reverseInorder(root->right);
        }
        cursum+=root->val;
        root->val=cursum;
        if(root->left)
        {
            reverseInorder(root->left);
        }
    }
    
    TreeNode* convertBST(TreeNode* root) 
    {
        if(root==NULL)
        {
            return root;
        }
        reverseInorder(root);
        return root;
    }
};