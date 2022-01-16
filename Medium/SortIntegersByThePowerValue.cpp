class Solution 
{
    public:
    
    void helper(int num,vector<pair<int,int> > &dp)
    {
        if (num%2==0)
        {
            if (dp[num/2].first==-1)
                helper(num/2,dp);
            dp[num].first=dp[num/2].first+1; 
        }
        else
        {
            if (dp[num*3+1].first==-1)
                helper(num*3+1,dp);   
            dp[num].first=dp[num*3+1].first+1;
        }
        dp[num].second=num;
    }
    
    bool static sortByChoice(pair<int,int> &p1,pair<int,int> &p2)
    {
        if (p1.first<p2.first)
        {
            return true;
        }
        else if (p1.first==p2.first)
        {
            if (p1.second<p2.second)
            {
                return true;
            }
            return false;
        }
        return false;
    }
    
    int getKth(int lo, int hi, int k) 
    {
        //First use memoisation to find the power of each value. Then sort in the required range and return the kth element
        vector<pair<int,int> > dp(1000000,{-1,-1});
        dp[0]={0,0};
        dp[1]={0,1};
        for (int i=hi;i>=lo;i--)
        {
            if (dp[i].first==-1)
                helper(i,dp);
        }
        
        sort(dp.begin()+lo,dp.begin()+hi+1);
        
        // for (int i=lo;i<=hi;i++)
        // {
        //     cout<<dp[i].first<<" "<<dp[i].second<<endl;
        // }
        // cout<<endl;
        return dp[lo-1+k].second;
    }
};