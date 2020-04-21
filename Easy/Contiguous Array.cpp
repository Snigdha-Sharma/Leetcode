class Solution 
{
    public:
    int findMaxLength(vector<int>& nums) 
    {
        if (nums.size()==0 || nums.size()==1)
        {
            return 0;
        }
        int csum=-1;
        unordered_map<int,int> umap;
        for (int i=0;i<nums.size();i++)
        {
            if (nums[i]==0)
            {
                nums[i]=-1;
            }
        }
        csum=nums[0];
        umap[nums[0]]=0;
        int ans=0;
        for (int i=1;i<nums.size();i++)
        {
            csum=csum+nums[i];
            if (csum==0)
            {
                ans=max(ans,i+1);
            }
            if (umap.find(csum)!=umap.end())
            {
                ans=max(ans,i-umap[csum]);
            }
            else
            {
                umap[csum]=i;
            }
        }
        return ans;
    }
};