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
    vector<TreeNode*> allPossibleFBT(int n) 
    {
        //When value of n is even you cannot make a full binary tree anyhow. Since in this question all nodes have value 0 we are basically supposed to return all possible structures. Use recursion
        vector<TreeNode*> ans;
        if (n%2==0)
        {
            vector<TreeNode*> ans;
            return ans;
        }
        if (n==1)
        {
            TreeNode *node=new TreeNode(0);
            ans.push_back(node);
            return ans;
        }
        for (int i=1;i<n;i+=2)
        {
            vector<TreeNode*> leftSubtrees=allPossibleFBT(i);
            vector<TreeNode*> rightSubtrees=allPossibleFBT(n-i-1);
            
            for (int j=0;j<leftSubtrees.size();j++)
            {
                
                for (int k=0;k<rightSubtrees.size();k++)
                {
                    TreeNode *root=new TreeNode(0);
                    root->left=leftSubtrees[j];
                    root->right=rightSubtrees[k];
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
};