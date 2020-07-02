//Similar problem to making a change using minimum number of coins

class Solution 
{
    public:
    int numSquares(int n) 
    {
        vector<int> change;
        for (int i=1;i*i<=n;i++)
        {
            change.push_back(i*i);
        }

        vector<int> dp;
        for (int i=0;i<=n;i++)
        {
            dp.push_back(INT_MAX);
        }
        
        dp[0]=0;

        
        for (int i=1;i<=n;i++)
        {
            for (int j=0;j<change.size();j++)
            {
                if (change[j]<=i)
                {
                    dp[i]=min(dp[i],dp[i-change[j]]+1);
                }
            }
        }
        return dp[n];
    }
};