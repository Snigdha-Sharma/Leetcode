class Solution 
{
    public:
    
    int makeTree(TreeNode *cur,int pos,vector<int> preorder,int sz,int l,int r)
    {
        if (pos==sz || preorder[pos]<l || preorder[pos]>r)
        {
            return pos;
        }
        if (preorder[pos]<cur->val)
        {
            cur->left=new TreeNode(preorder[pos]);
            pos++;
            pos=makeTree(cur->left,pos,preorder,sz,l,cur->val-1);
        }
        if (pos==sz || preorder[pos]<l || preorder[pos]>r)
        {
            return pos;
        }
        cur->right=new TreeNode(preorder[pos]);
        pos++;
        pos=makeTree(cur->right,pos,preorder,sz,cur->val+1,r);
        return pos;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) 
    {
        if (preorder.size()==0)
        {
            return NULL;
        }
        TreeNode *root=new TreeNode(preorder[0]);
        if (preorder.size()==1)
        {
            return root;
        }
        makeTree(root,1,preorder,preorder.size(),INT_MIN,INT_MAX);
        return root;
    }
};