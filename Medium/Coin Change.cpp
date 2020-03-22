class Solution 
{
    public:
    int coinChange(vector<int>& coins, int amount) 
    {
        long int dp[amount+1];
        for (long int k=0;k<=amount;k++)
        {
            dp[k]=10000000;
        }
        dp[0]=0;
        sort(coins.begin(),coins.end());
        for (long int i=1;i<=amount;i++)
        {
            for (long int j=0;j<coins.size() && i>=coins[j];j++)
            {
                dp[i]=min(dp[i-coins[j]]+1,dp[i]); 
            }
        }
        
        if (dp[amount]==10000000)
        {
            return -1;
        }
        return dp[amount];
    }
};