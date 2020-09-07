class Solution 
{
    public:
    int mincostTickets(vector<int>& days, vector<int>& costs) 
    {
        int sz=days[days.size()-1];
        vector<int> dp(sz+1,0);
        dp[days[0]]=costs[0];
        int count=0;
        for (int i=1;i<=sz;i++)
        {
            if (days[count]==i)
            {
                count++;
                dp[i]=min({dp[i-1]+costs[0],dp[max(0,i-7)]+costs[1],dp[max(0,i-30)]+costs[2]});
            }
			else
            {
                dp[i]=dp[i-1];
            }
			
        }
        // for (int i=0;i<=sz;i++)
        // {
        //     cout<<dp[i]<<" ";
        // }
        return dp[sz];
    }
};