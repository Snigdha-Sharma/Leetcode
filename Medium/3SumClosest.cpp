class Solution 
{
    public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        int dif=INT_MAX,sz=nums.size(),ans;
        sort(nums.begin(),nums.end());
        for (int i=0;i<sz;i++)
        {
            int low=i+1,high=sz-1,cursum;
            while(low<high)
            {
                cursum=nums[i]+nums[low]+nums[high];
                if (cursum==target)
                {
                    return target;
                }
                if (abs(target-cursum)<dif)
                {
                    dif=abs(target-cursum);
                    ans=cursum;
                } 
                if (cursum<target)
                {
                    low++;
                }
                else
                {
                    high--;
                }
            }
        }
        return ans;
    }
};