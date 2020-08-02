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
    
    int ans=0,greater=-10000;
    
    void countGoodNodes(TreeNode *root)
    {
        if (root->val>=greater)
        {
            greater=root->val;
            ans++;
        }
        if (root->left)
        {
            int temp_greater=greater;
            countGoodNodes(root->left);
            greater=temp_greater;
        }
        if (root->right)
        {
            int temp_greater=greater;
            countGoodNodes(root->right);
            greater=temp_greater;
        }
    }
    
    int goodNodes(TreeNode* root) 
    {
        if (root==NULL)
        {
            return 0;
        }
        if (root->left==NULL && root->right==NULL)
        {
            return 1;
        }
        countGoodNodes(root);
        return ans;
    }
};