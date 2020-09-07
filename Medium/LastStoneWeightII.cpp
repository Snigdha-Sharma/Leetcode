//Consider all possible signs for each element. Just try to optimise
class Solution 
{
    public:
    int lastStoneWeightII(vector<int>& stones) 
    {
        int n=stones.size();
        vector<set<int> > dp(n);
        dp[0].insert(stones[0]);
        dp[0].insert(-stones[0]);
        for (int i=1;i<stones.size();i++)
        {
            for (auto it=dp[i-1].begin();it!=dp[i-1].end();it++)
            {
                dp[i].insert(*it+stones[i]);
                dp[i].insert(*it-stones[i]);
            }
        }
        int ans=INT_MAX;
        for (auto it=dp[n-1].begin();it!=dp[n-1].end();it++)
        {
            ans=min(ans,abs(*it));
        }
        return ans;
    }
};