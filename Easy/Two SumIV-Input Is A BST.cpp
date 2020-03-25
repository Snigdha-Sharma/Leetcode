class Solution 
{
    public:
    vector<int> in;
    void inorder(TreeNode *root)
    {
        if (root!=NULL)
        {
            inorder(root->left);
            in.push_back(root->val);
            inorder(root->right);   
        }
    }
    
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> ans;
        vector<int> copy;
        int r=nums.size()-1;
        int l=0;
        for (auto i=nums.begin();i!=nums.end();i++)
        {
            copy.push_back(*i);
        }
        sort(nums.begin(),nums.end());
        int c=0;
        while(l<r)
        {
            if (nums[l]+nums[r]==target)
            {
                for (auto i=copy.begin();i!=copy.end();i++)
                {
                    if (*i==nums[l] || *i==nums[r])
                    {
                        ans.push_back(c);
                    }
                    c++;
                }
                break;
            }
            else if (nums[l]+nums[r]<target)
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        return ans;
    }
    
    bool findTarget(TreeNode* root, int k) 
    {
        inorder(root);
        vector<int> ans;
        ans=twoSum(in,k);
        if (ans.size()==2)
        {
            return true;
        }
        return false;
    }
};