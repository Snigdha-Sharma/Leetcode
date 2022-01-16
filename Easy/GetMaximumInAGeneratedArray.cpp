class Solution 
{
    public:
    int getMaximumGenerated(int n) 
    {
        //dp relation is already given. Generate the array and find the maximum value
        if (n==0)
        {
            return 0;
        }
        if (n==1)
        {
            return 1;
        }
        int ans=0;
        vector<int> dp(n+1,0);
        dp[1]=1;
        for (int i=2;i<=n;i++)
        {
            if (i%2==0)
            {
                dp[i]=dp[i/2];
            }
            else
            {
                dp[i]=dp[(i-1)/2]+dp[(i+1)/2];
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};