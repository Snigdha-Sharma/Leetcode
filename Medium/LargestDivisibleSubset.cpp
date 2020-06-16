class Solution 
{
    public:
    vector<int> largestDivisibleSubset(vector<int>& nums) 
    {
        vector<int> ans;
        if (nums.size()==0)
        {
            return ans;
        }
        sort(nums.begin(),nums.end());
        vector<int> divCount;
        vector<int> prev;
        for (int i=0;i<nums.size();i++)
        {
            divCount.push_back(1);
            prev.push_back(-1);
        }
        int max_idx=0;
        for (int i=1;i<nums.size();i++)
        {
            for (int j=0;j<i;j++)
            {
                if (nums[i]%nums[j]==0)
                {
                    if (divCount[i]<divCount[j]+1)
                    {
                        divCount[i]=divCount[j]+1;
                        prev[i]=j;
                    }
                }
            }
            if (divCount[max_idx] < divCount[i])
            {
                max_idx= i; 
            }
        }
        
        int k = max_idx; 
        while (k >= 0) 
        { 
            ans.push_back(nums[k]);
            k = prev[k]; 
        } 
        return ans;
    }
};