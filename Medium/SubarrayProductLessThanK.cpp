class Solution 
{
    public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) 
    {
        int n=nums.size(),ans=0;
        if (k<=1)
        {
            return 0;
        }
        int left=0,right=0,prod=1;
        while (right<n) 
        {
            prod*=nums[right];
            while (prod>=k)
            {
                prod/=nums[left++];
            }
            ans=ans+1+(right-left);//This is the case when we have to take all subarrays starting from left in that window
            right++;
        }
        return ans;
    }
};