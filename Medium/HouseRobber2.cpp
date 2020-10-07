//Find answer for both the conditions -Once when you dont consider the last house in your array and once when you dont consider the first house
// in the array

class Solution 
{
    public:
    
    int rob1(vector<int>& nums) 
    {
        int n=nums.size();
        if (n==0)
        {
            return 0;
        }
        if (n==1)
        {
            return nums[0];
        }
        if (n==2)
        {
            return max(nums[0],nums[1]);
        }
        vector<int> dp(n,0);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for (int i=2;i<n;i++)
        {
            dp[i]=max(dp[i-2]+nums[i],dp[i-1]);
        }
        return dp[n-1];
    }
    
    int rob(vector<int>& nums) 
    {
        int n=nums.size();
        if (n==0)
        {
            return 0;
        }
        if (n==1)
        {
            return nums[0];
        }
        if (n==2)
        {
            return max(nums[0],nums[1]);
        }
        vector<int> vec1,vec2;
        for (int i=0;i<n-1;i++)
        {
            vec1.push_back(nums[i]);
        }
        for (int i=1;i<n;i++)
        {
            vec2.push_back(nums[i]);
        }
        int x=rob1(vec1);
        int y=rob1(vec2);
        //cout<<"x="<<x<<",y="<<y;
        if (x>y)
        {
            return x;
        }
        return y;
    }
};