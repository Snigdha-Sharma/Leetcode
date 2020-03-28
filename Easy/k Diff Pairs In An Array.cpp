class Solution 
{
    public:
    int findPairs(vector<int>& nums, int k) 
    {
        sort(nums.begin(),nums.end());
        int slow=0,fast=1,ans=0;
        while(fast<nums.size() && slow<nums.size())
        {
            if (nums[fast]-nums[slow]==k)
            {
                ans++;
                fast++;
                slow++;
                while(fast<nums.size() && nums[fast]==nums[fast-1])
                {
                    fast++;
                }
            }
            else if (nums[fast]-nums[slow]>k)
            {
                slow++;
                if (slow==fast)
                {
                    fast++;
                }
            }
            else
            {
                fast++;
            }
        }
        return ans;
    }
};