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
    
    int height(TreeNode *root)
    {
	    if(root==NULL)
		    return 0;
	    return max(height(root->left),height(root->right))+1;
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) 
    {
        if(root==NULL)
		    return NULL;
	    int lheight=height(root->left);
	    int rheight=height(root->right);
	    if(lheight==rheight)
		    return root;
	    if(lheight>rheight)
		    return subtreeWithAllDeepest(root->left);
	    else
		    return subtreeWithAllDeepest(root->right);
    }
};