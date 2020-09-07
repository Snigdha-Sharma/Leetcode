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

//Simply based on inorder traversal of BST gives sorted array concept and merging two sorted arrays concept
class Solution 
{
    public:
    
    void getList(TreeNode* root,vector<int> &l)
    {
        //cout<<"WTH";
        if (root==NULL)
        {
            return;
        }
        getList(root->left,l);
        l.push_back(root->val);
        getList(root->right,l);
    }
    
    void showArray(vector<int> &v)
    {
        for (int i=0;i<v.size();i++)
        {
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) 
    {
        //cout<<"WERE ";
        vector<int> l1,l2;
        //cout<<"WOLF ";
        getList(root1,l1);
        //cout<<"Got l1 ";
        getList(root2,l2);
        //cout<<"got l2 ";
        vector<int> ans;
        //showArray(l1);
        //showArray(l2); 
        int i=0,j=0,n=l1.size(),m=l2.size();
        while(i<n && j<m)
        {
            if(l1[i]<l2[j])
            {
                ans.push_back(l1[i]);
                i++;
            }
            else if (l1[i]==l2[j])
            {
                ans.push_back(l1[i]);
                ans.push_back(l2[j]);
                i++;
                j++;
            }
            else
            {
                ans.push_back(l2[j]);
                j++;
            }
        }
        while(i<n)
        {
            ans.push_back(l1[i]);
            i++;
        }
        while(j<m)
        {
            ans.push_back(l2[j]);
            j++;
        }
        return ans;
    }
};