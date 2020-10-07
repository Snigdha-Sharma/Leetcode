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
    
    vector<string> helper(TreeNode *root)
    {
        vector<string> nums;
        if (root==NULL)
        {
            return nums;
        }
        else if (root->left==NULL && root->right==NULL)
        {
            nums.push_back(to_string(root->val));
        }
        vector<string> left=helper(root->left);
        vector<string> right=helper(root->right);
        for (int i=0;i<left.size();i++)
        {
            string temp=to_string(root->val)+left[i];
            nums.push_back(temp);
        }
        for (int i=0;i<right.size();i++)
        {
            string temp=to_string(root->val)+right[i];
            nums.push_back(temp);
        }
        return nums;
    }
    
    int convertBinaryStringToDecimal(string s)
    {
        int num=0,sz=s.size(),idx=sz-1;
        for (int i=0;i<sz;i++)
        {
            int k=0;
            if(s[i]=='1')
            {
                k=1;
            }
            num=num+pow(2,idx)*k;
            idx--;
        }
        return num;
    }
    
    int sumRootToLeaf(TreeNode* root) 
    {
        vector<string> allNums=helper(root);
        int ans=0;
        for (int i=0;i<allNums.size();i++)
        {
            string x=allNums[i];
            int num=convertBinaryStringToDecimal(x);
            ans=ans+num;
        }
        return ans;
    }
};