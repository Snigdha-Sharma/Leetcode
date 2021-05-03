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
    TreeNode* addOneRow(TreeNode* root, int v, int d) 
    {
        if(root==NULL)
        {
            return root;
        }
        if(d==1)
        {
            TreeNode *nroot=new TreeNode(v);
            nroot->left=root;
            return nroot;
        }
        queue<TreeNode *> q;
        q.push(root);
        for(int i=1;i<d-1;i++)
        {
            int sz=q.size();
            for(int l=0;l<sz;l++)
            {
                TreeNode *t=q.front();
                if(t->left)
                {
                    q.push(t->left);
                }
                if(t->right)
                {
                    q.push(t->right);
                }
                q.pop();
            }
        }
        while(!q.empty())
        {
            TreeNode *t=q.front();
            TreeNode *nLeft=new TreeNode(v);
            TreeNode *nRight=new TreeNode(v);
            if(t->left)
            {
                nLeft->left=t->left;
            }
            if(t->right)
            {
                nRight->right=t->right;
            }
            t->left=nLeft;
            t->right=nRight;
            q.pop();
        }
        return root;
    }
};