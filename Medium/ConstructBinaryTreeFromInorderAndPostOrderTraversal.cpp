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
    
    int search(vector<int> &inorder,int instart,int inend,int val)
    {
        int i=0;
        for (i=instart;i<=inend;i++)
        {
            if (inorder[i]==val)
            {
                break;
            }
        }
        return i;
    }
    
    int p;
    
    TreeNode* helper(vector<int> &inorder,vector<int> &postorder,int instart,int inend)
    {
        if (instart>inend)//If inorder array is exhausted
        {
            return NULL;
        }
        
        TreeNode *node=new TreeNode(postorder[p]);//Make new node which is root of current subarray
        
        p--;
        
        if(instart==inend)//If instart is equal to inend means their are no children of root
        {
            return node;
        }
        
        //Else search for the root in inorder subarray
        int idx=search(inorder,instart,inend,node->val);
        
        node->right=helper(inorder,postorder,idx+1,inend);
        //To get right children acess array from idx+1 to end
        node->left=helper(inorder,postorder,instart,idx-1);
        //To get left children access array from start to idx-1
        
        return node;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        p=postorder.size()-1;
        return helper(inorder,postorder,0,postorder.size()-1);
    }
};