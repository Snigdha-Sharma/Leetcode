class Solution 
{
    public:
    int lengthOfLIS(vector<int>& nums) 
    {
        vector<int> lis;//This vector stores the length of the LIS if you take he current number in the sequence
        for (int i=0;i<nums.size();i++)
        {
            lis.push_back(1);
        }
        for (int i=1;i<nums.size();i++)
        {
            for (int j=0;j<i;j++)
            {
                if (nums[i]>nums[j] && lis[i]<=lis[j])
                {
                    lis[i]=1+lis[j];
                }
            }
        }
        int ans=0;
        for (int i=0;i<lis.size();i++)
        {
            ans=max(ans,lis[i]);
        }
        return ans;
    }
};